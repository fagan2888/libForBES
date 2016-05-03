/* 
 * File:   SeparableSum.cpp
 * Author: Pantelis Sopasakis
 * 
 * Created on October 30, 2015, 7:22 PM
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

#include "SeparableSum.h"
#include <iostream>

/**
 * Constructs the sub-vector \c c_x which is defined by a given set of indexes.
 * 
 * @param c_idx set of indexes
 * @param x original vector x
 * @param c_x sub-vector
 */
void prepare_cx(std::vector<size_t> * c_idx, const Matrix& x, Matrix * c_x);

SeparableSum::~SeparableSum() {
}

SeparableSum::SeparableSum(std::map<Function*, std::vector<size_t>*> fun_idx_map) :
Function(), m_fun_idx_map(fun_idx_map) {
}

void prepare_cx(std::vector<size_t> * c_idx, const Matrix& x, Matrix * c_x) {
    size_t k = 0;
    for (std::vector<size_t>::iterator idx_iterator = c_idx->begin();
            idx_iterator != c_idx->end();
            ++idx_iterator) {
        c_x -> set(k, 0, x.get(*idx_iterator, 0));
        k++;
    }
}

int SeparableSum::call(Matrix& x, double& f) {
    //LCOV_EXCL_START
    if (!x.isColumnVector()) throw std::invalid_argument("x must be a column-vector");
    //LCOV_EXCL_STOP

    /* sub-matrix */
    Matrix *c_x = NULL;

    /* initialization of result f(x) */
    f = 0.0;


    /* Invoke all functions */
    for (std::map<Function*, std::vector<size_t> * >::iterator map_iterator = m_fun_idx_map.begin()
            ; map_iterator != m_fun_idx_map.end()
            ; ++map_iterator) {
        /* current vector of indices*/
        std::vector<size_t> * c_idx = NULL;

        /* temporary value of sub-invocations */
        double f_temp;

        /* status of sub-invocations   */
        int status;

        /* Pointer to current function */
        Function * c_fun = NULL;
        c_fun = map_iterator->first;

        /* Function indices         */
        c_idx = map_iterator->second;

        /* initialize new sub-matrix */
        c_x = new Matrix(c_idx->size(), 1);

        /* iterator for the indices of c_fun */
        prepare_cx(c_idx, x, c_x);

        /* invoke sub-function on c_x, return f_temp */
        status = c_fun -> call(*c_x, f_temp);
        if (ForBESUtils::is_status_error(status)) {
            delete c_x;
            c_x = NULL;
            return status;
        }
        f += f_temp;
    }

    if (c_x != NULL) {
        delete c_x;
        c_x = NULL;
    }
    return ForBESUtils::STATUS_OK;
}

int SeparableSum::call(Matrix& x, double& f, Matrix& grad) {
    Matrix *c_x = NULL;
    f = 0.0;
    Matrix *c_grad = NULL;
    /* Invoke all functions */
    for (std::map<Function*, std::vector<size_t> * >::iterator map_iterator = m_fun_idx_map.begin()
            ; map_iterator != m_fun_idx_map.end()
            ; ++map_iterator) {
        std::vector<size_t> * c_idx = NULL;
        double f_temp;
        int status;
        Function * c_fun = NULL;
        c_fun = map_iterator->first;
        c_idx = map_iterator->second;
        c_x = new Matrix(c_idx->size(), 1);
        prepare_cx(c_idx, x, c_x);
        c_grad = new Matrix(c_idx->size(), 1);
        status = c_fun -> call(*c_x, f_temp, *c_grad);

        if (ForBESUtils::is_status_error(status)) {
            delete c_x;
            c_x = NULL;
            delete c_grad;
            c_grad = NULL;
            return status;
        }

        size_t k = 0;
        std::vector<size_t>::iterator idx_iterator;
        for (idx_iterator = c_idx->begin(); idx_iterator != c_idx->end(); ++idx_iterator) {
            grad[*idx_iterator] = c_grad->get(k);
            k++;
        }

        f += f_temp;
    }

    if (c_x != NULL) {
        delete c_x;
        c_x = NULL;
    }
    if (c_grad != NULL) {
        delete c_grad;
        c_grad = NULL;
    }
    return ForBESUtils::STATUS_OK;
}

int SeparableSum::callProx(Matrix& x, double gamma, Matrix& prox) {
    //LCOV_EXCL_START
    if (!x.isColumnVector()) {
        throw std::invalid_argument("x must be a column-vector");
    }
    //LCOV_EXCL_STOP

    Matrix *c_x = NULL;
    Matrix *c_prox = NULL;

    for (std::map<Function*, std::vector<size_t> * >::iterator map_iterator = m_fun_idx_map.begin()
            ; map_iterator != m_fun_idx_map.end()
            ; ++map_iterator) {
        Function * c_fun = map_iterator->first;
        std::vector<size_t> * c_idx = map_iterator->second;
        c_x = new Matrix(c_idx->size(), 1);
        prepare_cx(c_idx, x, c_x);

        c_prox = new Matrix(c_idx->size(), 1);
        int status = c_fun -> callProx(*c_x, gamma, *c_prox);
        if (ForBESUtils::is_status_error(status)) {
            delete c_x;
            delete c_prox;
            return status;
        }
        size_t k = 0;
        std::vector<size_t>::iterator idx_iterator;
        for (idx_iterator = c_idx->begin(); idx_iterator != c_idx->end(); ++idx_iterator) {
            prox[*idx_iterator] = c_prox->get(k);
            k++;
        }
    }
    if (c_x != NULL) delete c_x;
    if (c_prox != NULL) delete c_prox;
    return ForBESUtils::STATUS_OK;
}

int SeparableSum::callProx(Matrix& x, double gamma, Matrix& prox, double& f_at_prox) {
    //LCOV_EXCL_START
    if (!x.isColumnVector()) {
        throw std::invalid_argument("x must be a column-vector");
    }
    //LCOV_EXCL_STOP

    Matrix *c_x = NULL;
    Matrix *c_prox = NULL;

    f_at_prox = 0.0;
    double f_at_prox_temp = 0.0;
    for (std::map<Function*, std::vector<size_t> * >::iterator map_iterator = m_fun_idx_map.begin()
            ; map_iterator != m_fun_idx_map.end()
            ; ++map_iterator) {
        Function * c_fun = map_iterator->first;
        std::vector<size_t> * c_idx = map_iterator->second;
        c_x = new Matrix(c_idx->size(), 1);
        prepare_cx(c_idx, x, c_x);

        c_prox = new Matrix(c_idx->size(), 1);
        int status = c_fun -> callProx(*c_x, gamma, *c_prox, f_at_prox_temp);
        f_at_prox += f_at_prox_temp;

        //LCOV_EXCL_START
        if (ForBESUtils::STATUS_OK != status) {
            delete c_x;
            delete c_prox;
            return status;
        }
        //LCOV_EXCL_STOP

        size_t k = 0;
        std::vector<size_t>::iterator idx_iterator;
        for (idx_iterator = c_idx->begin(); idx_iterator != c_idx->end(); ++idx_iterator) {
            prox[*idx_iterator] = c_prox->get(k);
            k++;
        }
    }
    if (c_x != NULL) delete c_x;
    if (c_prox != NULL) delete c_prox;
    return ForBESUtils::STATUS_OK;
}

int SeparableSum::callConj(Matrix& x, double& f_star) {
    //LCOV_EXCL_START
    if (!x.isColumnVector()) {
        throw std::invalid_argument("x must be a column-vector");
    }
    //LCOV_EXCL_STOP
    f_star = 0.0;

    std::map<Function*, std::vector<size_t> * >::iterator map_iterator;
    Function * c_fun = NULL;
    Matrix *c_x = NULL;

    for (map_iterator = m_fun_idx_map.begin(); map_iterator != m_fun_idx_map.end(); ++map_iterator) {
        std::vector<size_t> * c_idx = NULL;
        c_fun = map_iterator->first; // current function
        c_idx = map_iterator->second; // current index set I
        c_x = new Matrix(c_idx->size(), 1); // prepare current vector
        prepare_cx(c_idx, x, c_x);

        double f_star_temp;
        int status = c_fun -> callConj(*c_x, f_star_temp);
        if (ForBESUtils::is_status_error(status)) {
            delete c_x;
            c_x = NULL;
            return status;
        }
        f_star += f_star_temp;
    }
    if (c_x != NULL) {
        delete c_x;
        c_x = NULL;
    }
    return ForBESUtils::STATUS_UNDEFINED_FUNCTION;
}

FunctionOntologicalClass SeparableSum::category() {
    FunctionOntologicalClass meta("SeparableSum");
    meta.set_defines_f(true);
    meta.set_defines_grad(true);
    meta.set_defines_prox(true);
    meta.set_defines_conjugate(true);
    meta.add_superclass(FunctionOntologyRegistry::function());
    return meta;
}


