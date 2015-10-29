/* 
 * File:   DistanceToBox.cpp
 * Author: Pantelis Sopasakis
 * 
 * Created on October 27, 2015, 6:05 PM
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

#include "DistanceToBox.h"

void checkBounds(const Matrix* lb, const Matrix* ub) {
    if (lb->isEmpty()) {
        throw std::invalid_argument("Lower bound is not allowed to be empty");
    }
    if (ub->isEmpty()) {
        throw std::invalid_argument("Upper bound is not allowed to be empty");
    }
    if (!lb->isColumnVector() || !ub->isColumnVector()) {
        throw std::invalid_argument("UB and LB must be column vectors");
    }
    if (ub->getNcols() != lb->getNcols() || ub->getNrows() != lb->getNrows()) {
        throw std::invalid_argument("UB and LB must be vectors of the same size");
    }
    if (lb->getType() != Matrix::MATRIX_DENSE || ub->getType() != Matrix::MATRIX_DENSE) {
        throw std::invalid_argument("UB and LB must be dense vectors - other types are not supported");
    }
}

DistanceToBox::DistanceToBox(Matrix* lb, Matrix* ub, Matrix* weights) :
Function(), m_lb(lb), m_ub(ub), m_weights(weights) {
    checkBounds(lb, ub);
    m_is_weights_equal = false;
}

DistanceToBox::DistanceToBox(Matrix* lb, Matrix* ub, double weight) :
Function(), m_lb(lb), m_ub(ub), m_weight(weight) {
    checkBounds(lb, ub);
    m_is_weights_equal = true;
}

DistanceToBox::~DistanceToBox() {

}

int DistanceToBox::compute_dx(const Matrix& x, const size_t n, Matrix& dx) const {
    for (size_t i = 0; i < n; i++) {
        if (!m_is_bounds_uniform) {
            if (x.get(i, 0) < m_lb->get(i, 0)) {
                dx.set(i, 0, x.get(i, 0) - m_lb->get(i, 0));
            } else if (x.get(i, 0) > m_ub->get(i, 0)) {
                dx.set(i, 0, x.get(i, 0) - m_ub->get(i, 0));
            }
        }
    }
    return ForBESUtils::STATUS_OK;
}

int DistanceToBox::compute_grad(Matrix& dx, const size_t n, Matrix& grad) const {
    if (!m_is_weights_equal) {
        for (size_t i = 0; i < n; i++) {
            grad.set(i, 0, m_weights->get(i, 0) * dx.get(i, 0));
        }
    } else {
        grad = m_weight * dx;
    }
    return ForBESUtils::STATUS_OK;
}

int DistanceToBox::compute_fun(const Matrix& dx, const size_t n, double& f) const {
    f = 0.0;
    for (size_t i = 0; i < n; i++) {
        f += m_weights->get(i, 0) * std::pow(dx.get(i, 0), 2);
    }
    f /= 2.0;
    return ForBESUtils::STATUS_OK;
}

int DistanceToBox::call(Matrix& x, double& f, Matrix& grad) {
    const size_t n = x.getNrows();            // input dimension
    Matrix dx(n, 1);                    // dx : n-by-1 (all zeros)
    compute_dx(x, n, dx);               // compute d(x)
    compute_grad(dx, n, grad);          // compute the gradient
    compute_fun(dx, n, f);              // compute f(x)
    return ForBESUtils::STATUS_OK;      // OK
}

int DistanceToBox::call(Matrix& x, double& f) {
    const size_t n = x.getNrows();            // input dimension
    Matrix dx(n, 1);                    // dx : n-by-1 (all zeros)
    compute_dx(x, n, dx);               // compute d(x)
    compute_fun(dx, n, f);              // compute f(x)
    return ForBESUtils::STATUS_OK;      // OK
}

int DistanceToBox::category() {
    return Function::CAT_UNCATEGORIZED;
}