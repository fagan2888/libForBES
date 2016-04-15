/* 
 * File:   LBFGSBuffer.cpp
 * Author: Pantelis Sopasakis
 *
 * Created on April 13, 2016, 2:32 PM
 * 
 * Original source code:
 * https://github.com/lostella/libLBFGS
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

#include "LBFGSBuffer.h"
#include "Matrix.h"
#include "MatrixFactory.h"
#include <iostream>
#include <string.h>
#include <complex>

const long LBFGSBuffer::LBFGS_BUFFER_EOB = -1;

LBFGSBuffer::LBFGSBuffer(size_t n, size_t mem) : m_mem(mem) {
    // initialize the LBFGS buffer
    m_current_mem = 0;
    m_idx = -1;
    // allocate memory for matrices
    m_S = new Matrix(n, mem);
    m_Y = new Matrix(n, mem);
    m_Ys = new Matrix(mem, 1);
    m_alphas = new Matrix(mem, 1);
}

LBFGSBuffer::~LBFGSBuffer() {
    if (m_S != NULL) {
        delete m_S;
    }
    if (m_Y != NULL) {
        delete m_Y;
    }
    if (m_Ys != NULL) {
        delete m_Ys;
    }
    if (m_alphas != NULL) {
        delete m_alphas;
    }
    m_mem = 0;
    m_current_mem = 0;
    m_idx = 0;
}

Matrix* LBFGSBuffer::get_S() const {
    return m_S;
}

Matrix* LBFGSBuffer::get_Y() const {
    return m_Y;
}

Matrix* LBFGSBuffer::get_Ys() const {
    return m_Ys;
}

Matrix* LBFGSBuffer::get_alphas() const {
    return m_alphas;
}

long LBFGSBuffer::cursor() const {
    return m_idx;
}

int LBFGSBuffer::push(Matrix* s, Matrix* y) {
    m_idx++;
    if (m_idx >= m_mem) {
        m_idx = 0; // start over
    }
    m_current_mem++; // increase current memory
    if (m_current_mem > m_mem) {
        m_current_mem = m_mem; // buffer is now full
    }

    size_t n = m_Y->getNrows();

    // copy data into m_Y
    double * m_Y_data = m_Y->getData();
    double * y_data = y->getData();
    m_Y_data += m_idx*n;
    memcpy(m_Y_data, y_data, n * sizeof (double));

    // copy data into m_S
    double * m_S_data = m_S->getData();
    double * s_data = s->getData();
    m_S_data += m_idx*n;
    memcpy(m_S_data, s_data, n * sizeof (double));

    Matrix s_mat = MatrixFactory::ShallowVector(s_data, n, 0);
    Matrix y_mat = MatrixFactory::ShallowVector(y_data, n, 0);
    Matrix ys = y_mat*s_mat;
    m_Ys->set(m_idx, 0, ys[0]);
    return ForBESUtils::STATUS_OK;
}

int LBFGSBuffer::reset() {
    m_idx = -1;
    m_current_mem = 0;
    return ForBESUtils::STATUS_OK;
}

size_t LBFGSBuffer::get_current_mem() const {
    return m_current_mem;
}

double LBFGSBuffer::hessian_estimate() {
    // returns Hk0 = ys_prev / (y_prev'*y_prev)
    // or 1.0 is no ys_prev is cached
    size_t idx_current = get_k_minus_j(0);
    size_t n = m_Y->getNrows();
    double gamma_k_0 = 1.0;
    if (m_current_mem > 0) {
        Matrix curr_y = MatrixFactory::ShallowSubVector(*m_Y, idx_current);
        double sq_norm_y = 0.0;
        for (size_t l = 0; l < n; l++) {
            sq_norm_y += std::pow(curr_y[l], 2);
        }
        gamma_k_0 = (*m_Ys)[idx_current] / sq_norm_y;
    }
    return gamma_k_0;
}

int LBFGSBuffer::update(const Matrix* q, Matrix* r, double& gamma0) {
    Matrix qq = *q;

    /*
     * STEP 1:  First loop (compute alpha, update qq)
     * [TESTED]
     */
    long k_minus_j;
    long j = 0;
    while ((k_minus_j = get_k_minus_j(j)) != LBFGSBuffer::LBFGS_BUFFER_EOB) {
        Matrix sq = MatrixFactory::ShallowSubVector(*m_S, k_minus_j) * qq; // <si, q_i>
        Matrix yi = MatrixFactory::ShallowSubVector(*m_Y, k_minus_j); // yi
        double alpha_i = sq[0] / (*m_Ys)[k_minus_j];
        (*m_alphas)[k_minus_j] = alpha_i;
        Matrix::add(qq, -alpha_i, yi, 1.0);
        j++;
    }

    /* Update r */
    *r = gamma0 * qq;



    /*
     * STEP 2:      Second loop
     */
    j = m_mem;

    // skip empty buffer
    while (j >= 0 &&
            (k_minus_j = get_k_minus_j(j)) == LBFGSBuffer::LBFGS_BUFFER_EOB) j--;


    // iterate backwards
    while (j >= 0) {
        k_minus_j = get_k_minus_j(j);
        Matrix yi = MatrixFactory::ShallowSubVector(*m_Y, k_minus_j);
        Matrix b = yi * (*r);
        double beta = b[0] / (*m_Ys)[k_minus_j];
        Matrix s = MatrixFactory::ShallowSubVector(*m_S, k_minus_j);
        Matrix::add(*r, (*m_alphas)[k_minus_j] - beta, s, 1.0);
        j--;
    }

    return ForBESUtils::STATUS_OK;
}

