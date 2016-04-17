/* 
 * File:   Function.cpp
 * Author: Pantelis Sopasakis
 * 
 * Created on July 9, 2015, 3:35 AM
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

#include "Function.h"

Function::Function() {
}

Function::~Function() {
}

//LCOV_EXCL_START

int Function::call(Matrix& x, double& f) {
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}

int Function::call(Matrix& x, double& f, Matrix& grad) {
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}
//LCOV_EXCL_STOP

int Function::hessianProduct(Matrix& x, Matrix& z, Matrix& Hz) {
    const double epsilon = 1e-8;
    const double one_over_epsilon = 1e8;

    /* t = x + epsilon * z */
    Matrix t(x);
    Matrix::add(t, epsilon, z, 1.0);


    Matrix grad_x(x.getNrows(), x.getNcols());

    double f;
    /* Hz = nabla f(x+e*z) */
    int status = call(t, f, Hz);

    /* grad_x = nabla f(x) */
    status = std::max(status, call(x, f, grad_x));

    /* Hz = (nabla f(t) - nabla f(x))/epsilon */
    Hz -= grad_x;
    Hz *= one_over_epsilon;

    return status;
}

int Function::callConj(Matrix& x, double& f_star) {
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}

int Function::callConj(Matrix& x, double& f_star, Matrix& grad) {
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}

int Function::hessianProductConj(Matrix& x, Matrix& z, Matrix& Hz) {
    const double epsilon = 1e-8;
    const double one_over_epsilon = 1e8;

    /* t = x + epsilon * z */
    Matrix t(x);
    Matrix::add(t, epsilon, z, 1.0);


    Matrix grad_x(x.getNrows(), x.getNcols());
    double f;
    int status = callConj(t, f, Hz);
    status = std::max(status, callConj(x, f, grad_x));
    Hz -= grad_x;
    Hz *= one_over_epsilon;
    return status;
}

//LCOV_EXCL_START
int Function::callProx(Matrix& x, double gamma, Matrix& prox) {
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}

int Function::callProx(Matrix& x, double gamma, Matrix& prox, double& f_at_prox) {
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}
//LCOV_EXCL_STOP

Function& Function::operator=(const Function& right) {
    if (this == &right) { // Check for self-assignment!
        return *this;
    } else {
        // otherwise it should not be allowed to use operator= on Functions!
        // an error should be thrown
        throw logic_error("It is not allowed to copy Function objects; operator= is not supported.");
    }
}
