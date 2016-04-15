/*
 * File:   CongSeparableSum.h
 * Author: Pantelis Sopasakis
 *
 * April 14, 2016, 4:04 PM
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

#ifndef CONGSEPARABLESUM_H
#define CONGSEPARABLESUM_H

#include "Function.h"
#include <vector>

class CongSeparableSum : public Function {
public:

    /**
     * 
     * @param n_functions
     * @param splitting
     * @param functions
     */
    CongSeparableSum(
            size_t n_functions,
            std::vector<size_t> splitting,
            std::vector<Function*> functions);

    /**
     * Destructor
     */
    virtual ~CongSeparableSum();

    virtual int call(Matrix& x, double& f);

private:
    int m_n_functions; /**< number of functions */
    std::vector<size_t> m_splitting; /**< assignment of arguments (congruently) */
    std::vector<Function*> m_functions; /**< registry of functions */
};

#endif /* CONGSEPARABLESUM_H */

