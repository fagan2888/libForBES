/*
 * File:   FBCache.h
 * Author: Lorenzo Stella
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

#ifndef FBCACHE_H
#define FBCACHE_H

#include "Matrix.h"
#include "FBProblem.h"

/**
 * \class FBCache
 * \brief Low-level forward-backward operations management class
 * \version version 0.0
 * \ingroup FBSolver-group
 * 
 * FBCache handles forward-backward operations related to an FBProblem
 * In particular, objects of the FBCache class are initialized given an
 * FBProblem p, a point x (of class Matrix) and a scalar parameter gamma.
 * It allows to evaluate the proximal-gradient operation starting from x,
 * and the value of the forward-backward envelope function (FBE) associated
 * with p.
 */
class FBCache {
private:

    /*
     * We declare TestFBCache as a `friend` to be able to test private methods.
     */
    friend class TestFBCache;    

    int m_status; /**< Cache status. Indicated what has been cached. */
    bool m_cached_grad_f2; /**< whether the gradient of f2 is to be computed along with its value. */
    bool m_betas_fresh; /**< whether beta1 and beta2 are fresh */
    bool m_lind_fresh; /**< whether the inner product (l,d) is fresh */
    bool m_L2d_fresh; /**< whether L2*d is fresh */
    bool m_fxtd_fresh; /**< whether m_fxtd is cached and fresh */

    FBProblem & m_prob; /**< Specifications of the underlying optimization problem. */
    Matrix * m_x; /** Current point (x). */

    /* Internal storage for computing proximal-gradient steps */
    Matrix * m_y; /**< x-gamma nabla f(x) */
    Matrix * m_z; /**< prox_{gamma g} (y) =  prox_{gamma g} ( x - gamma * nabla f(x))  */
    Matrix * m_FPRx; /**< x-z (fixed point residual) - see also m_sqnormFPRx */
    Matrix * m_res1x; /**< L1*x + d1 */
    Matrix * m_gradf1x; /**< nabla f_1 (res1x)*/
    Matrix * m_res2x; /**< L2*x + d2 */
    Matrix * m_gradf2x; /**< nabla f_2 (res2x) */
    Matrix * m_gradfx; /**< f(x) = f1(L1*x+d1) + f2(L2*x+d2); gradfx = nabla f(x) */
    Matrix * m_gradFBEx; /**< gradient of the FB envelope */
    Matrix * m_dir; /**< direction (d). */
    Matrix * m_L2d; /**< Matrix v = L2[d] cached to facilitate the extrapolation on f2 */
    Matrix * m_Qu; /**< Q*L1[d] */
    double m_f1x; /**< f1(res1x) */
    double m_f2x; /**< f2(res2x) */
    double m_linx; /**< l'*x */
    double m_lind; /**< l'*d */
    double m_fx; /**< f(x) */
    double m_gz; /**< g(z) */
    double m_gamma; /**< parameter gamma */
    double m_FBEx; /**< FBE(x) */
    double m_sqnormFPRx; /**< Squared norm-2 of the FPR ||x-z||^2 - see also m_FPRx */
    double m_beta1; /**< Parameter used to determin f1(x+tau*d) */
    double m_beta2; /**< Parameter used to determin f1(x+tau*d) - see #f1_extrapolate */
    double m_tau; /**< tau */
    double m_fxtd; /**< cached value of f(x+tau*d) which is fresh if <code>m_fxtd_fresh == true</code> */

protected:
    
    /**
     * Computes \f$f_1(r_1(x+\tau d))\f$ for the stored values of \f$x\f$ and \f$d\f$.
     * 
     * It makes use of the formula
     * 
     * \f[
     *  f_1(r_1(x+\tau d)) = f_1(r_1(x)) + \beta_1 \tau + \beta_2 \tau^2,
     * \f]
     * 
     * where \f$\beta_1 = \langle u, (\nabla f_1)(r_1(x))\f$, \f$\beta_2 = u'Qu/2\f$
     * and \f$u=L_1 d\f$.
     * 
     * \post After successful completion, the \link #cache_status status \endlink 
     * of the cache will be at least #STATUS_EVALF.
     * 
     * @param tau parameter \f$\tau\f$
     * @param fxtd result \f$f_1(r_1(x+\tau d))\f$
     * @return status code: returns \link ForBESUtils::STATUS_OK STATUS_OK\endlink 
     * if the method has succeeded,
     * \link ForBESUtils::STATUS_CACHE_NO_DIRECTION STATUS_CACHE_NO_DIRECTION\endlink 
     * if no direction \f$d\f$ is provided, 
     * and \link ForBESUtils::STATUS_CACHE_NO_QUADRATIC STATUS_CACHE_NO_QUADRATIC\endlink 
     * if there is no quadratic function \f$f_1\f$ defined in which case, it sets 
     * \c fxtd to <code>0.0</code>.
     * 
     * \sa extrapolate_f
     * \sa cache_status
     * \sa extrapolate_fbe
     */
    int extrapolate_f1(double tau, double& fxtd);

    /**
     * Computes \f$f(x+\tau d)\f$ for the stored values of \f$x\f$ and \f$d\f$.
     * 
     * It uses the formula
     * 
     * \f[
     *  f(x+\tau d) = f_1(r_1(x+\tau d)) + \langle l, x\rangle + 
     *    \tau \langle l, d\rangle + f_2(r_2(x) + \tau v),
     * \f]
     * 
     * where \f$v=L_2 d\f$ and \f$f_1(r_1(x+\tau d))\f$ is computed using 
     * #extrapolate_f1.
     * 
     * \post After successful completion, the \link #cache_status status \endlink 
     * of the cache will be at least #STATUS_EVALF.
     * 
     * @param tau scalar parameter \f$\tau\f$
     * @param fxtd result \f$f(x+\tau d)\f$ for the given \f$\tau\f$
     * @return status code: returns \link ForBESUtils::STATUS_OK STATUS_OK\endlink 
     * if the method has succeeded, \link ForBESUtils::STATUS_CACHE_NO_DIRECTION 
     * STATUS_CACHE_NO_DIRECTION\endlink if no direction \f$d\f$ is provided.
     * 
     * \sa extrapolate_f1
     * \sa extrapolate_gradf
     * \sa extrapolate_fbe
     */
    int extrapolate_f(double tau, double& fxtd);

    /**
     * Computes the gradient of \f$f\f$ at \f$x+\tau d\f$ that is \f$\nabla f(x+\tau d)\f$
     * for the stored values of \f$x\f$ and \f$d\f$.
     * 
     * @param tau scalar parameter \f$\tau\f$
     * @param grad_xtd the resulting gradient 
     * @return status code: returns \link ForBESUtils::STATUS_OK STATUS_OK\endlink 
     * if the method has succeeded, \link ForBESUtils::STATUS_CACHE_NO_DIRECTION 
     * STATUS_CACHE_NO_DIRECTION\endlink if no direction \f$d\f$ is provided.
     * 
     * \sa extrapolate_fbe
     */
    int extrapolate_gradf(double tau, Matrix& grad_xtd);

    /**
     * Constructs and returns the matrix \f$x+\tau d\f$ for the stored matrices
     * \f$x\f$ and \f$d\f$.
     * 
     * @param tau scalar parameter \f$\tau\f$
     * @param xtd matrix <code>x + tau * d </code>
     * @return status code: returns \link ForBESUtils::STATUS_OK STATUS_OK\endlink 
     * if the method has succeeded, \link ForBESUtils::STATUS_CACHE_NO_DIRECTION 
     * STATUS_CACHE_NO_DIRECTION\endlink if no direction \f$d\f$ is provided.
     */
    int xtd(double tau, Matrix& xtd_matrix);
    
    /**
     * Evaluates \f$f(x)\f$ and updates the internal status of FBCache.
     * 
     * Function \f$f\f$ is evaluated as
     * \f[
     *   f(x) = f_1(L_1x + d_1) + f_2(L_2 x + d_2) + \langle l, x \rangle.
     * \f]
     * 
     * If the value of \f$f\f$ has already been computed at this particular point 
     * \f$x\f$, the the method returns STATUS_OK without re-computing this value
     * as it has been cached.
     *
     * @param order_grad_f2 whether the gradient of \f$f_2\f$ should be computed
     * alongside the value of this function. This may often be computationally more
     * favourable compared to the separate computation of the value and the gradient.
     * 
     * @return status code (see ForBESUtils); returns a 
     * \link ForBESUtils::STATUS_OK STATUS_OK\endlink 
     * if the computation was successful and sets the internal status of the cache to 
     * \link FBCache::STATUS_EVALF STATUS_EVALF\endlink. If the result was cached, 
     * it returns a \link ForBESUtils::STATUS_CACHED_ALREADY STATUS_CACHED_ALREADY\endlink.
     */
    int update_eval_f(bool order_grad_f2);

    /**
     * Evaluates the forward (gradient) step at x with parameter gamma,
     * and updates the internal status.
     * 
     * The forward step is defined as
     * \f[
     * y = x - \gamma \nabla f(x).
     * \f]
     *
     * @return Status code, see ForBESUtils. If the result was cached, 
     * it returns a \link ForBESUtils::STATUS_CACHED_ALREADY STATUS_CACHED_ALREADY\endlink.
     */
    int update_forward_step(double gamma);

    /**
     * Evaluates the forward-backward (or proximal-gradient) step at x with parameter gamma,
     * and updates the internal status.
     * 
     * This method updates and caches the fixed point residual
     * \f[
     *   R_\gamma(x) = x - \mathrm{prox}_{\gamma g}(x-\gamma \nabla f(x)),
     * \f]
     * and it also computes and stores its squared norm \f$\|R_\gamma(x)\|^2\f$.
     *
     * @return Status code, see ForBESUtils. If the result was cached, 
     * it returns a \link ForBESUtils::STATUS_CACHED_ALREADY STATUS_CACHED_ALREADY\endlink.
     */
    int update_forward_backward_step(double gamma);

    /**
     * Evaluates the FBE at x with parameter gamma,
     * and updates the internal status.
     * 
     * The FBE is computed as
     * \f[
     *  \varphi_\gamma(x) = f(x) + g(\mathrm{prox}_{\gamma g}(x-\gamma \nabla f(x))) -
     *                      \nabla f(x)^{\top}R_{\gamma}(x) + \frac{1}{2\gamma}\|R_\gamma(x)\|^2,
     * \f]
     * where
     * \f[
     *   R_\gamma(x) = x - \mathrm{prox}_{\gamma g}(x-\gamma \nabla f(x)),
     * \f]
     * is the fixed-point residual (FPR).
     * 
     * @return Status code, see ForBESUtils. If the result was cached, 
     * it returns a \link ForBESUtils::STATUS_CACHED_ALREADY STATUS_CACHED_ALREADY\endlink.
     */
    int update_eval_FBE(double gamma);

    /**
     * Evaluates the gradient of the FBE at x with parameter gamma,
     * and updates the internal status. 
     * 
     * The gradient of the FBE is given by
     * 
     * \f[
     *  \nabla \varphi_\gamma(x) = (I-\gamma \nabla_x^2 f(x))R_\gamma(x),
     * \f]
     *
     * where \f$R_\gamma(x)=x-z(x)\f$ is the <em>fixed-point residual</em> with 
     * \f$z(x) = \mathrm{prox}_{\gamma g}(x-\gamma \nabla f(x))\f$ .
     * 
     * 
     * @return Status code, see ForBESUtils. If the result was cached, 
     * it returns a \link ForBESUtils::STATUS_CACHED_ALREADY STATUS_CACHED_ALREADY\endlink.
     */
    int update_grad_FBE(double gamma);

    /**
     * Used to set the internal status of the object at a specific value.
     * For example, if the point at which to evaluate operations is changed
     * (using set_point) then the status is reset to 
     * \c #STATUS_NONE; if \c gamma instead is changed, the status is reset to 
     * \c #STATUS_EVALF. In fact, the value of f is independent of gamma, and is 
     * not to be recomputed.
     * 
     * @param status a status code (see static private const members)
     */
    void reset(int status);

public:

    /**
     * 
     * 
     * The internal state of FBCache is stale, or it has not been updated.
     */
    static const int STATUS_NONE;
    /**
     * 
     * 
     * The following are available:
     * * The <em>residuals</em> \f$ r_1(x)=L_1 x + d_1 \f$ and \f$ r_2(x)=L_2 x + d_2 \f$
     * * The product \f$ \langle l, x \rangle \f$
     * * The values \f$ f_1(r_1(x)) \f$ and \f$ f_2(r_2(x)) \f$
     * * The value of \f$ f(x) = f_1(r_1(x)) + f_2(r_2(x))\f$
     * * The gradient of \f$f_1\f$ at the corresponding residual, \f$ \nabla f_1( r_1(x) ) \f$
     * 
     */
    static const int STATUS_EVALF;

    /**
     * 
     * 
     * The data which correspond to #STATUS_EVALF are available and, additionally,
     * the following are available
     * * The gradient of \f$f_2\f$ at the corresponding residual, \f$ \nabla f_2( r_2(x) ) \f$
     * * The gradient of \f$f\f$ at \f$x\f$, that is \f$\nabla f(x)\f$
     * * The value of \f$y = x - \gamma \nabla f(x)\f$
     */
    static const int STATUS_FORWARD;
    /**
     * 
     * Everything that corresponds to #STATUS_FORWARD (and #STATUS_EVALF) has been
     * computed and is cached and available and, additionally,
     * * The proximal \f$z=\mathrm{prox}_{\gamma g}(y)\f$ where \f$y = x - \gamma \nabla f(x)\f$     
     * * The value \f$g(z)\f$
     * * The square norm of the fixed point residual, that is \f$\|x-z\|^2\f$
     */
    static const int STATUS_FORWARDBACKWARD;

    /**
     *
     * The forward backward envelope \f$\varphi_\gamma(x)\f$ has been computed and
     * it is cached. Additionally, all data which correspond to #STATUS_FORWARDBACKWARD
     * have been computed and are available.
     */
    static const int STATUS_FBE;

    /**
     * 
     * All information which has been computed up to level #STATUS_FBE is available
     * and, furthermore, the gradient of the FBE, that is \f$\nabla \varphi_\gamma(x)\f$
     * has also been computed and is cached.
     */
    static const int STATUS_GRAD_FBE;


    /**
     * Initialize an FBCache object
     *
     * @param p reference to FBProblem
     * @param x reference to Matrix, the point at which to perform the operations
     * @param gamma the initial stepsize parameter for the operations
     */
    FBCache(FBProblem & p, Matrix & x, double gamma);

    /**
     * Default destructor.
     */
    virtual ~FBCache();

    /**
     * Sets the point to which the FBCache object refers.
     * 
     * Once a new point is provided to the cache, its internal status is set to
     * \link FBCache::STATUS_NONE STATUS_NONE\endlink.
     *
     * @param x new point at which to evaluate the steps
     * 
     * \sa get_point
     */
    void set_point(Matrix& x);


    /**
     * Passes a new direction to the current modifiable cache which is cached 
     * internally.
     * 
     * \note Before this method is invoked for the first time, no memory is allocated
     * for the direction.
     * 
     * @param d direction
     * 
     * \sa set_point
     */
    void set_direction(Matrix& d);

    /**
     * Returns a pointer to the currently stored direction
     * @return internally stored direction
     * 
     * \sa set_direction
     */
    Matrix * get_direction();

    /**
     * Gets (a pointer to) the point \f$x\f$ to which the FBCache object refer
     *
     * @return a pointer to Matrix containing the handled point
     * 
     * \sa set_point
     */
    Matrix * get_point();

    /**
     * Gets the result of the forward (gradient) step given by 
     * \f$x-\gamma \nabla f(x)\f$, with step-size \f$\gamma\f$, at the stored point 
     * \f$x\f$.
     * 
     * If the forward step for the current values of \f$x\f$ and \f$\gamma\f$ has not
     * been computed previously, it is computed and cached the first time that 
     * this method is called.
     * 
     *
     * @param gamma stepsize parameter
     * @return a pointer to Matrix containing the forward step
     * 
     * \sa update_forward_step
     * \sa set_point
     */
    Matrix * get_forward_step(double gamma);

    /**
     * Gets the result of the forward-backward (proximal-gradient) with step-size 
     * \f$\gamma\f$ at \f$x\f$, that is 
     * \f$z=\mathrm{prox}_{\gamma g}(y)\f$ where \f$y = x - \gamma \nabla f(x)\f$ 
     *
     * @param gamma step-size parameter
     * @return a pointer to Matrix containing the forward-backward step
     * 
     * \sa update_forward_backward_step
     */
    Matrix * get_forward_backward_step(double gamma);

    /**
     * Gets the fixed-point residual at \f$x\f$ with parameter \f$\gamma\f$
     *
     * @return a pointer to Matrix containing the fixed-point residual
     * 
     * \sa update_forward_backward_step
     */
    Matrix * get_fpr();

    /**
     * Gets the norm of the fixed point residual (FPR) which is defined as
     * \f[
     *   R_{\gamma}(x) = x - \mathrm{prox}_{\gamma g}(x - \gamma \nabla f(x)),
     * \f]
     * where \f$f\f$ is assume to to differentiable and \f$g\f$ is such that it
     * is possible to compute its proximal.
     *
     * @return Euclidean norm of the fixed-point residual, that is \f$R_{\gamma}(x)\f$
     * 
     * \sa update_forward_backward_step
     */
    double get_norm_fpr();

    /**
     * Gets the value of \f$f\f$ at \f$x\f$
     *
     * @return \f$f(x)\f$
     * 
     * \sa update_eval_f
     */
    double get_eval_f();

    /**
     * Gets the value of the forward-backward envelope function (FBE) 
     * at the current value of \f$x\f$ with a given parameter \f$\gamma\f$
     *
     * @param gamma stepsize parameter
     * @return value of the FBE at x with parameter gamma
     * 
     * \sa update_eval_FBE
     */
    double get_eval_FBE(double gamma);

    /**
     * Gets the gradient of the FBE at x with a given parameter gamma
     *
     * @param gamma stepsize parameter
     * @return pointer to Matrix containing the gradient of the FBE
     * 
     * \sa update_grad_FBE
     */
    Matrix * get_grad_FBE(double gamma);

    /**
     * Returns the gradient of \f$f\f$. 
     * 
     * \note Note that this matrix may have not been computed - especially if
     * the \link #cache_status() status\endlink of the cache is smaller than #STATUS_FORWARD.
     * 
     * \note To compute the gradient of f call \link #get_forward_step(double) get_forward_step\endlink.
     * 
     * @return Pointer to cached gradient of \c f.
     */
    Matrix * get_gradf() const;

    /**
     * The internal status of the cache.
     * * #STATUS_NONE
     * * #STATUS_EVALF
     * * #STATUS_FORWARD
     * * #STATUS_FORWARDBACKWARD
     * * #STATUS_FBE
     * * #STATUS_GRAD_FBE
     * @return status of the cache
     */
    int cache_status() const;

    /**
     * Erases the internal status of the cache, i.e., sets its status to
     * \link FBCache::STATUS_NONE STATUS_NONE\endlink. This means that any 
     * getter will require to recompute everything.
     * steps.
     */
    void reset();

    /**
     * 
     * Computes the value of \f$\varphi_\gamma(x+\tau d)\f$ for the cached values 
     * of \f$x\f$ (using #set_point) and \f$d\f$ (using #set_direction).
     * 
     * The extrapolation is based on the formula
     * 
     * \f[
     *  \varphi_\gamma(x+\tau d) = 
     *         f(x+\tau d) + g(z(x+\tau d)) + \frac{1}{2\gamma}\|R_\gamma(x+\tau d)\|^2
     *         - \langle \nabla f(x+\tau d), R_\gamma(x+\tau d) \rangle
     * \f]
     * 
     * where \f$z(x+\tau d) = \mathrm{prox}_{\gamma g}(y(x+\tau d))\f$ and
     * \f$y(x+\tau d) = x + \tau d - \gamma \nabla f(x+\tau d)\f$ and 
     * \f$R_\gamma(x+\tau d) = x+\tau d - z(x+\tau d)\f$.
     * 
     * The values of \f$f(x+\tau d)\f$ and \f$\nabla f(x+\tau d)\f$ are computed
     * efficiently using #extrapolate_f and #extrapolate_gradf.
     * 
     * \pre it is necessary that you provide a direction \f$d\f$ before you invoke
     * this method.
     * 
     * 
     * @param tau parameter \f$\tau\f$
     * @param gamma parameter \f$\gamma\f$ of the FBE
     * @param fbe (output) value of \f$\varphi_\gamma(x+\tau d)\f$
     * @return status code: \link ForBESUtils::STATUS_OK STATUS_OK\endlink on success, 
     * \link ForBESUtils::STATUS_CACHE_NO_DIRECTION STATUS_CACHE_NO_DIRECTION\endlink 
     * if no direction is available.
     * 
     * \sa extrapolate_f
     * \sa extrapolate_f1
     * \sa extrapolate_gradf
     */
    int extrapolate_fbe(double tau, double gamma, double& fbe);

};

#endif /* FBCACHE_H */
