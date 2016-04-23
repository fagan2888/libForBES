/*
 * File:   FBCache.cpp
 * Author: Lorenzo Stella, Pantelis Sopasakis
 *
 * Created on October 2, 2015
 *
 * ForBES is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ForBES is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with ForBES. If not, see <http://www.gnu.org/licenses/>.
 */

#include "FBCache.h"
#include "LinearOperator.h"

#include <cmath>
#include <limits>
#include <complex>

#define FB_CACHE_RELATIVE_TOL 1e-6
#define FB_CACHE_ABSOLUTE_TOL 1e-14

const int FBCache::STATUS_NONE = 0;
const int FBCache::STATUS_EVALF = 1;
const int FBCache::STATUS_FORWARD = 2;
const int FBCache::STATUS_FORWARDBACKWARD = 3;
const int FBCache::STATUS_FBE = 4;
const int FBCache::STATUS_GRAD_FBE = 5;

/**
 * Verify whether \c a and \c b are close to one another. Checks whether 
 * \f[
 *  |a-b|\leq \max (\epsilon_r \max(a,b), \epsilon_a),
 * \f]
 * where \f$\epsilon_r = 10^{-6}\f$ is the relative tolerance and \f$\epsilon_a=10^{-14}\f$
 * is the absolute tolerance.
 * 
 * 
 * @param a scalar
 * @param b another scalar
 * @return \c true iff \c a is approximately equal to \c b.
 */
inline bool is_close(const double a, const double b) {
    return abs(a - b) <= std::max(
            FB_CACHE_RELATIVE_TOL * std::max(std::abs(a), std::abs(b)),
            FB_CACHE_ABSOLUTE_TOL);
}

void FBCache::reset(int status) {
    if (status < m_status) m_status = status;
}

void FBCache::reset() {
    FBCache::reset(STATUS_NONE);
    m_betas_fresh = false;
    m_lind_fresh = false;
    m_L2d_fresh = false;
    m_fxtd_fresh = false;
    m_cached_grad_f2 = false;
}

FBCache::FBCache(FBProblem & p, Matrix & x, double gamma) :
m_prob(p),
m_x(&x),
m_gamma(gamma) {
    m_status = STATUS_NONE;
    m_betas_fresh = false;
    m_lind_fresh = false;
    m_L2d_fresh = false;
    m_fxtd_fresh = false;
    m_cached_grad_f2 = false;

    // get dimensions of things
    size_t m_x_rows = m_x->getNrows();
    size_t m_x_cols = m_x->getNcols();
    size_t m_res2_rows, m_res2_cols;

    if (m_prob.d2() != NULL) {
        m_res2_rows = m_prob.d2()->getNrows();
        m_res2_cols = m_prob.d2()->getNcols();
    } else if (m_prob.L2() != NULL) {
        m_res2_rows = m_prob.L2()->dimensionOut().first;
        m_res2_cols = m_prob.L2()->dimensionOut().second;
    } else {
        m_res2_rows = m_x_rows;
        m_res2_cols = m_x_cols;
    }


    m_res2x = NULL;
    m_gradf2x = NULL;

    if (m_prob.f2() != NULL) {
        m_res2x = new Matrix(m_res2_rows, m_res2_cols);
        m_gradf2x = new Matrix(m_res2_rows, m_res2_cols);
    }

    m_gradf1x = NULL;
    m_gradfx = NULL;
    m_z = NULL;
    m_y = NULL;
    m_FPRx = NULL;
    m_gradFBEx = NULL;
    m_dir = NULL;
    m_L2d = NULL;
    m_Qu = NULL;

    m_FBEx = std::numeric_limits<double>::infinity();
    m_sqnormFPRx = std::numeric_limits<double>::infinity();
    m_tau = std::numeric_limits<double>::infinity();

    m_f1x = 0.0;
    m_f2x = 0.0;
    m_linx = 0.0;
    m_fx = 0.0;
    m_gz = 0.0;

}

int FBCache::update_eval_f(bool order_grad_f2) {

    if (!m_cached_grad_f2 && order_grad_f2) {
        // If gradf2x has not been computed previously, but now should be
        // computed, then set the status to STATUS_NONE, so that all 
        // computations are performed from the beginning (both f2x and gradf2x).
        m_status = STATUS_NONE;
    }

    if (m_status >= STATUS_EVALF) return ForBESUtils::STATUS_CACHED_ALREADY;

    if (m_prob.f1() != NULL) {
        // quadratic

        /* Compute the residual m_res1x (allocate mem if necessary) */
        if (m_prob.L1() == NULL && m_prob.d1() == NULL) {
            /* if there are no L1, d1, allocate no memory for m_res1x */
            m_res1x = m_x;
        } else {
            /* if at least one of L1, d1 is defined, allocate memory for m_resx1 */
            if (m_prob.d1() != NULL) {
                m_res1x = new Matrix(m_prob.d1()->getNrows(), m_prob.d1()->getNcols());
            }
            if (m_prob.L1() != NULL) {
                m_res1x = new Matrix(m_prob.L1()->dimensionOut());
                /* If L1 is defined, compute L1[x] */
                *m_res1x = m_prob.L1()->call(*m_x);
            }
            if (m_prob.d1() != NULL) *m_res1x += *m_prob.d1();
        }
        if (m_gradf1x == NULL) m_gradf1x = new Matrix(m_res1x->getNrows(), m_res1x->getNcols());
        int call_status = m_prob.f1()->call(*m_res1x, m_f1x, *m_gradf1x);
        if (!ForBESUtils::is_status_ok(call_status)) return call_status;

    }

    if (m_prob.f2() != NULL) {
        if (m_prob.L2() != NULL) {
            *m_res2x = m_prob.L2()->call(*m_x);
        } else {
            *m_res2x = *m_x;
        }
        if (m_prob.d2() != NULL) {
            *m_res2x += *(m_prob.d2());
        }
        int status =
                order_grad_f2
                ? m_prob.f2()->call(*m_res2x, m_f2x, *m_gradf2x)
                : m_prob.f2()->call(*m_res2x, m_f2x);
        m_cached_grad_f2 = order_grad_f2;
        if (!ForBESUtils::is_status_ok(status)) return status;

    }

    if (m_prob.lin() != NULL) {
        m_linx = ((*m_prob.lin()) * (*m_x))[0];
    }

    m_fx = m_f1x + m_f2x + m_linx;
    m_status = STATUS_EVALF;

    return ForBESUtils::STATUS_OK;
}

int FBCache::update_forward_step(double gamma) {

    if (m_y == NULL) m_y = new Matrix();
    if (m_gradfx == NULL) m_gradfx = new Matrix(m_x->getNrows(), m_x->getNcols());

    bool is_gamma_the_same = is_close(gamma, m_gamma);
    if (!is_gamma_the_same) reset(STATUS_EVALF);


    if (m_status >= STATUS_FORWARD) {
        if (is_gamma_the_same) return ForBESUtils::STATUS_CACHED_ALREADY;
        *m_y = *m_x;
        Matrix::add(*m_y, -gamma, *m_gradfx, 1.0);
        m_gamma = gamma;
        return ForBESUtils::STATUS_OK;
    }

    int status;

    if (m_status < STATUS_EVALF) {
        m_cached_grad_f2 = false;
        status = update_eval_f(true);
        if (!ForBESUtils::is_status_ok(status)) return status;
    }

    if (m_prob.f1() != NULL) {
        if (m_prob.L1()) {
            Matrix d_gradfx = m_prob.L1()->callAdjoint(*m_gradf1x);
            *m_gradfx = d_gradfx;
        } else {
            *m_gradfx = *m_gradf1x;
        }
    }

    if (m_prob.f2() != NULL) {
        if (!m_cached_grad_f2) {
            status = m_prob.f2()->call(*m_res2x, m_f2x, *m_gradf2x);
            if (!ForBESUtils::is_status_ok(status)) return status;
            // now gradf2x has been computed:
            m_cached_grad_f2 = true;
        }
        if (m_prob.L2() != NULL) {
            Matrix d_gradfx = m_prob.L2()->callAdjoint(*m_gradf2x);
            if (m_prob.f1() != NULL) *m_gradfx += d_gradfx;
            else *m_gradfx = d_gradfx;
        } else {
            if (m_prob.f1() != NULL) *m_gradfx += *m_gradf2x;
            else *m_gradfx = *m_gradf2x;
        }
    }

    if (m_prob.lin()) {
        if (m_prob.f1() != NULL || m_prob.f2() != NULL) {
            *m_gradfx += (*m_prob.lin());
        } else {
            *m_gradfx = *m_prob.lin();
        }
    }

    *m_y = *m_x;
    Matrix::add(*m_y, -gamma, *m_gradfx, 1.0);

    m_gamma = gamma;
    m_status = STATUS_FORWARD;
    m_cached_grad_f2 = true;
    return ForBESUtils::STATUS_OK;
}

int FBCache::update_forward_backward_step(double gamma) {
    int status;

    /* Allocate memory if necessary */
    if (m_z == NULL) m_z = new Matrix(m_x->getNrows(), m_x->getNcols());
    if (m_FPRx == NULL) m_FPRx = new Matrix();

    if (!is_close(gamma, m_gamma)) {
        reset(STATUS_EVALF);
    }
    if (m_status >= STATUS_FORWARDBACKWARD) return ForBESUtils::STATUS_CACHED_ALREADY;
    if (m_status < STATUS_FORWARD) {
        status = update_forward_step(gamma);
        if (!ForBESUtils::is_status_ok(status)) {
            return status;
        }
    }

    status = m_prob.g()->callProx(*m_y, gamma, *m_z, m_gz);
    if (!ForBESUtils::is_status_ok(status)) return status;

    *m_FPRx = (*m_x - *m_z);
    m_sqnormFPRx = std::pow(m_FPRx->norm_fro(), 2);
    m_gamma = gamma;
    m_status = STATUS_FORWARDBACKWARD;

    return ForBESUtils::STATUS_OK;
}

int FBCache::update_eval_FBE(double gamma) {
    if (!is_close(gamma, m_gamma)) {
        reset(STATUS_EVALF);
    }

    if (m_status >= STATUS_FBE) return ForBESUtils::STATUS_CACHED_ALREADY;

    if (m_status < STATUS_FORWARDBACKWARD) {
        int status = update_forward_backward_step(gamma);
        if (!ForBESUtils::is_status_ok(status)) {
            return status;
        }
    }

    Matrix innprox_mat = (*m_FPRx) * (*m_gradfx);
    double innprod = innprox_mat[0];

    m_FBEx = m_fx + m_gz - innprod + 0.5 / m_gamma*m_sqnormFPRx;
    m_gamma = gamma;
    m_status = STATUS_FBE;

    return ForBESUtils::STATUS_OK;
}

int FBCache::update_grad_FBE(double gamma) {
    if (!is_close(gamma, m_gamma)) {
        reset(STATUS_EVALF);
    }

    if (m_gradFBEx == NULL) m_gradFBEx = new Matrix();

    if (m_status >= STATUS_GRAD_FBE) return ForBESUtils::STATUS_CACHED_ALREADY;

    if (m_status < STATUS_FORWARDBACKWARD) {
        int status = update_forward_backward_step(gamma);
        if (!ForBESUtils::is_status_ok(status)) return status;
    }

    *m_gradFBEx = *m_FPRx;

    if (m_prob.f1() != NULL) {
        if (m_prob.L1() != NULL) {
            Matrix v1(m_prob.L1()->dimensionOut());
            v1 = m_prob.L1()->call(*m_FPRx);
            Matrix v2(m_prob.L1()->dimensionOut());
            m_prob.f1()->hessianProduct(*m_res1x, v1, v2);
            Matrix v3 = m_prob.L1()->callAdjoint(v2);
            Matrix::add(*m_gradFBEx, -1.0, v3, 1.0 / gamma);
        } else {
            Matrix v1(m_x->getNrows(), m_x->getNcols());
            m_prob.f1()->hessianProduct(*m_x, *m_FPRx, v1);
            Matrix::add(*m_gradFBEx, -1.0, v1, 1.0 / gamma);
        }
    }

    if (m_prob.f2() != NULL) {
        if (m_prob.L2() != NULL) {
            Matrix v1(m_prob.L2()->dimensionOut());
            v1 = m_prob.L2()->call(*m_FPRx);
            Matrix v2(m_prob.L2()->dimensionOut());
            m_prob.f2()->hessianProduct(*m_res2x, v1, v2);
            Matrix v3 = m_prob.L2()->callAdjoint(v2);
            if (m_prob.f1() != NULL) Matrix::add(*m_gradFBEx, -1.0, v3, 1.0);
            else Matrix::add(*m_gradFBEx, -1.0, v3, 1.0 / gamma);
        } else {
            Matrix v1(m_x->getNrows(), m_x->getNcols());
            m_prob.f2()->hessianProduct(*m_x, *m_FPRx, v1);
            if (m_prob.f1() != NULL) Matrix::add(*m_gradFBEx, -1.0, v1, 1.0);
            else Matrix::add(*m_gradFBEx, -1.0, v1, 1.0 / gamma);
        }
    }

    m_gamma = gamma;
    m_status = STATUS_GRAD_FBE;

    return ForBESUtils::STATUS_OK;
}

void FBCache::set_point(Matrix& x) {
    *m_x = x;
    reset(STATUS_NONE);
    m_betas_fresh = false;
    m_lind_fresh = false;
    m_fxtd_fresh = false;
    m_cached_grad_f2 = false;
}

Matrix * FBCache::get_point() {
    return m_x;
}

void FBCache::set_direction(Matrix& d) {
    /* the first time this method is called, allocate memory */
    if (m_dir == NULL) {
        m_dir = new Matrix();
    }
    *m_dir = d;
    m_betas_fresh = false;
    m_lind_fresh = false;
    m_L2d_fresh = false;
    m_fxtd_fresh = false;
    m_cached_grad_f2 = false;
}

Matrix* FBCache::get_direction() {
    return m_dir;
}

double FBCache::get_eval_FBE(double gamma) {
    update_eval_FBE(gamma);
    return m_FBEx;
}

Matrix * FBCache::get_grad_FBE(double gamma) {
    update_grad_FBE(gamma);
    return m_gradFBEx;
}

double FBCache::get_eval_f() {
    update_eval_f(false);
    return m_fx;
}

Matrix* FBCache::get_forward_step(double gamma) {
    update_forward_step(gamma);
    return m_y;
}

Matrix* FBCache::get_gradf() const {
    return m_gradfx;
}

int FBCache::cache_status() const {
    return m_status;
}

Matrix* FBCache::get_forward_backward_step(double gamma) {
    update_forward_backward_step(gamma);
    return m_z;
}

Matrix* FBCache::get_fpr() {
    update_forward_backward_step(m_gamma);
    return m_FPRx;
}

double FBCache::get_norm_fpr() {
    update_forward_backward_step(m_gamma);
    return sqrt(m_sqnormFPRx);
}

int FBCache::extrapolate_fbe(double tau, double gamma, double& fbe) {
    fbe = 0.0;

    /* if tau has changed, set m_fxtd_fresh to false */
    if (std::isinf(m_tau) || !is_close(tau, m_tau)) m_fxtd_fresh = false;

    /* compute x_tau_d = x + tau*d */
    Matrix x_tau_d(m_x->getNrows(), m_x->getNcols());
    int status = xtd(tau, x_tau_d);
    if (!ForBESUtils::is_status_ok(status)) return status;

    /* compute the gradient of f at x + tau*d (and f(x+tau*d)*/
    Matrix grad_xtd;
    status = extrapolate_gradf(tau, grad_xtd);
    if (!ForBESUtils::is_status_ok(status)) return status;

    /* Update FBE (1) */
    fbe = m_fxtd;

    /* Compute y(x+tau*d) = x_tau_d - gamma*gradf_xtd */
    Matrix y_xtd = x_tau_d;
    Matrix::add(y_xtd, -gamma, grad_xtd, 1.0);

    /* Compute z(x+tau*d) = prox_(gamma*g)(y_xtd)*/
    double g_z_xtd; // g(z(x+tau*d))
    Matrix z_xtd(y_xtd.getNrows(), y_xtd.getNcols()); // z(x+tau*d)
    status = m_prob.g()->callProx(y_xtd, gamma, z_xtd, g_z_xtd);
    if (!ForBESUtils::is_status_ok(status)) return status;

    /* Update FBE (2) */
    fbe += g_z_xtd;

    /* Compute the FPR(x+tau*d) = x + tau*d - z(x+tau*d) */
    Matrix * fpr;
    fpr = &z_xtd;
    Matrix::add(*fpr, 1.0, x_tau_d, -1.0);

    /* Update FBE (3) */
    fbe += std::pow(fpr->norm_fro(), 2) * 0.5 / gamma;

    /* Update FBE (4) */
    fbe -= (grad_xtd * (*fpr))[0];

    return ForBESUtils::STATUS_OK;
}

int FBCache::extrapolate_f1(double tau, double& fxtd) {
    if (m_dir == NULL) return ForBESUtils::STATUS_CACHE_NO_DIRECTION;
    if (m_prob.f1() == NULL) {
        fxtd = 0.0;
        return ForBESUtils::STATUS_CACHE_NO_QUADRATIC;
    }
    if (m_status < STATUS_EVALF) update_eval_f(false);

    if (!m_betas_fresh) {
        Matrix * u; /* should we cache this? */
        if (m_prob.L1() != NULL) {
            u = new Matrix();
            *u = m_prob.L1()->call(*m_dir);
        } else {
            u = m_dir;
        }
        m_beta1 = static_cast<Matrix> ((*u)*(*m_gradf1x))[0];
        if (m_Qu == NULL) m_Qu = new Matrix();
        m_prob.f1()->hessianProduct(*m_x, *u, *m_Qu);
        m_beta2 = static_cast<Matrix> ((*u) * (*m_Qu))[0] / 2;
        m_betas_fresh = true; /* beta1 and beta2 are now cached */
    }

    /* Compute fxtd = f1x + tau * beta1 + tau^2 * beta2 */
    fxtd = m_f1x + m_beta1 * tau + m_beta2 * std::pow(tau, 2);
    return ForBESUtils::STATUS_OK;

}

int FBCache::extrapolate_f(double tau, double& fxtd) {
    if (m_dir == NULL) return ForBESUtils::STATUS_CACHE_NO_DIRECTION;
    if (m_status < STATUS_EVALF) update_eval_f(false);
    if (m_fxtd_fresh && !isinf(m_tau) && is_close(tau, m_tau)) {
        fxtd = m_fxtd;
        return ForBESUtils::STATUS_CACHED_ALREADY;
    }
    int status;
    fxtd = 0.0;

    if (m_prob.f1() != NULL) {
        status = extrapolate_f1(tau, fxtd);
        if (!ForBESUtils::is_status_ok(status)) return status;
    }

    /* += <l,x> + tau * <l,d> */
    if (m_prob.lin() != NULL) {
        fxtd += m_linx;
        if (!m_lind_fresh) {
            /* compute and cache the inner product (lin,d) */
            m_lind = ((*m_prob.lin())*(*m_dir))[0];
            m_lind_fresh = true;
        }
        fxtd += (tau * m_lind);
    }

    /* += f2(r2(x) + tau * L2[d]) */
    if (m_prob.f2() != NULL) {
        if (!m_L2d_fresh) {
            if (m_prob.L2() != NULL) {
                m_L2d = new Matrix();
                *m_L2d = m_prob.L2()->call(*m_dir);
            } else {
                /* careful how you delete this later... */
                m_L2d = m_dir;
            }
            m_L2d_fresh = true;
        }
        Matrix r2xtd(*m_res2x);
        Matrix::add(r2xtd, tau, *m_L2d, 1.0);
        double f2val = 0.0;
        status = m_prob.f2()->call(r2xtd, f2val);
        if (!ForBESUtils::is_status_ok(status)) return status;
        fxtd += f2val;
    }
    m_tau = tau;
    m_fxtd = fxtd;
    m_fxtd_fresh = true;
    return ForBESUtils::STATUS_OK;
}

int FBCache::extrapolate_gradf(double tau, Matrix& grad_xtd) {
    int status;
    if (m_dir == NULL) return ForBESUtils::STATUS_CACHE_NO_DIRECTION;

    /* 
     * this ensures that extrapolate_f has been previously invoked and that 
     * fxtd is fresh in the cache:
     */
    double fxtd;
    if (!m_fxtd_fresh) {
        status = extrapolate_f(tau, fxtd);
        if (!ForBESUtils::is_status_ok(status)) return status;
    }

    /* Gradient of f1(r1(x+tau*d)) */
    /* __gradf1_xtd : grad_f1(r1(x)) + tau * (Q*u) */
    if (m_prob.f1() != NULL) {
        // gradient of quadratic
        Matrix __gradf1_xtd = *m_gradf1x;
        Matrix::add(__gradf1_xtd, tau, *m_Qu, 1.0);
        if (m_prob.L1() == NULL) {
            grad_xtd = __gradf1_xtd;
        } else {
            grad_xtd = m_prob.L1()->callAdjoint(__gradf1_xtd);
        }
    }
    /* Add the constant term (m_lin) */
    if (m_prob.lin() != NULL) {
        grad_xtd += *m_prob.lin();
    }

    /* Non-quadratic */
    if (m_prob.f2() != NULL) {
        /* __res2_xtd = m_res2x + tau * L2*d   */
        Matrix __res2_xtd = *m_res2x;
        Matrix::add(__res2_xtd, tau, *m_L2d, 1.0);
        double f2_xtd_temp;
        Matrix gradf2_xtd(2, 1);
        status = m_prob.f2()->call(__res2_xtd, f2_xtd_temp, gradf2_xtd);
        if (!ForBESUtils::is_status_ok(status)) return status;
        if (m_prob.L2() != NULL) {
            Matrix f = m_prob.L2()->callAdjoint(gradf2_xtd);
            grad_xtd += f;
        } else {
            grad_xtd += gradf2_xtd;
        }

    }


    return ForBESUtils::STATUS_OK;
}

int FBCache::xtd(double tau, Matrix& xtd_matrix) {
    if (m_dir == NULL) return ForBESUtils::STATUS_CACHE_NO_DIRECTION;
    xtd_matrix = *m_x;
    Matrix::add(xtd_matrix, tau, *m_dir, 1.0);
    return ForBESUtils::STATUS_OK;
}

FBCache::~FBCache() {
    if (m_z != NULL) {
        delete m_z;
        m_z = NULL;
    }
    if (m_y != NULL) {
        delete m_y;
        m_y = NULL;
    }
    if (m_res2x != NULL) {
        delete m_res2x;
        m_res2x = NULL;
    }
    if (m_gradf2x != NULL) {
        delete m_gradf2x;
        m_gradf2x = NULL;
    }
    /* if both L1 and d1 are NULL, there has been no mem alloc for m_res1x*/
    if (m_res1x != NULL && (m_prob.L1() != NULL || m_prob.d1() != NULL)) {
        delete m_res1x;
        m_res1x = NULL;
    }
    if (m_gradf1x != NULL) {
        delete m_gradf1x;
        m_gradf1x = NULL;
    }
    if (m_gradfx != NULL) {
        delete m_gradfx;
        m_gradfx = NULL;
    }
    if (m_FPRx != NULL) {
        delete m_FPRx;
        m_FPRx = NULL;
    }
    if (m_gradFBEx != NULL) {
        delete m_gradFBEx;
        m_gradFBEx = NULL;
    }
    if (m_dir != NULL) {
        delete m_dir;
        m_dir = NULL;
    }
    if (m_L2d != NULL && m_L2d != m_dir) {
        delete m_L2d;
        m_L2d = NULL;
    }
    if (m_Qu != NULL) {
        delete m_Qu;
        m_Qu = NULL;
    }
}
