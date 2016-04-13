/* 
 * File:   LBFGSBuffer.h
 * Author: Pantelis Sopasakis, Lorenzo Stella
 *
 * Created on April 13, 2016, 2:32 PM
 * 
 * This file (LBFGSBuffer.h) as well as the corresponding implementation
 * is a C++-translation of the original source code of L. Stella (libLBFGS) which
 * can be found at https://github.com/lostella/libLBFGS.
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

#ifndef LBFGSBUFFER_H
#define LBFGSBUFFER_H


#include "Matrix.h"
#include "MatrixFactory.h"

class LBFGSBuffer {
public:

    /**
     * 
     * This constant signals the <em>end of buffer</em> (EOB) while
     * accessing past (buffered) values.
     */
    static const long LBFGS_BUFFER_EOB;

    /**
     * Constructs a new instance of LBFGSBuffer for vectors of size \c n 
     * and using a memory length \c mem.
     * 
     * @param n size of x
     * @param mem memory
     */
    LBFGSBuffer(size_t n, size_t mem);

    /**
     * Default destructor.
     */
    virtual ~LBFGSBuffer();

    /**
     * Buffered values of \f$s_{k} = x_{k+1} - x_{k}\f$
     * @return pointer to buffered data for all \c s
     */
    Matrix* get_S() const;

    /**
     * Buffered values of \f$y_{k} = \nabla f_{k+1} - \nabla f_{k}\f$
     * @return pointer to buffered data for all \c y
     */
    Matrix* get_Y() const;

    
    /**
     * Buffered values of \f$\psi_{k} = \langle s_k, y_k \rangle\f$
     * @return pointer to buffered data for all \c y
     */
    Matrix* get_Ys() const;

    /**
     * Internal buffer used for values \f$\alpha_k\f$
     * @return 
     */
    Matrix* get_alphas() const;

    /**
     * Current index
     * @return 
     */
    long get_idx() const;

    /**
     * Provide a new pair \f$(s,y)\f$ to the buffer. This method updates the 
     * buffers of \c s, \c y and of their inner product.
     * 
     * @param s
     * @param y
     * @return returns \link ForBESUtils::STATUS_OK STATUS_OK\endlink on success
     */
    int push(Matrix * s, Matrix * y);

    /**
     * Resets all buffers.
     * @return 
     */
    int reset();

    /**
     * Perform the two-loop update and computes
     * \f[
     *  r_k = H_k q_k,
     * \f]
     * for a given vector \f$q_k\f$.
     * 
     * Details about the algorithm can be found in J. Nocedal and S.J. Wright,
     * <em>Numerical Optimization</em>, Second edition, Springer, 2006 (see Alg.
     * 7.4).
     * 
     * @param q given vector \f$q_k\f$
     * @param r result
     * @return Returns \link ForBESUtils::STATUS_OK STATUS_OK\endlink on success
     */
    int update(Matrix * q, Matrix * r);

    /**
     * @param j
     * @return 
     */
    inline long get_k_minus_j(size_t j) {
        register long t = m_idx - j;
        if (t >= 0) {
            return t;
        } else if (m_current_mem < m_mem || j >= m_mem) {
            return LBFGS_BUFFER_EOB;
        } else {
            return (m_mem + t);
        }
    }

private:

    size_t m_mem; /**< memory length */
    size_t m_current_mem; /**< current memory (the buffer may not be full) */
    long m_idx; /**< current index */
    Matrix * m_S; /**< Buffer of past s_k */
    Matrix * m_Y; /**< Buffer of past y_k */
    Matrix * m_Ys; /**< Buffer of past values of y_k'*s_k */
    Matrix * m_alphas; /**< The alphas in the two-loop recursion (loop 1) */


};

#endif /* LBFGSBUFFER_H */

