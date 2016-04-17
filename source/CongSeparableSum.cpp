/*
 * File:   CongSeparableSum.cpp
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

#include "CongSeparableSum.h"
#include "MatrixFactory.h"

CongSeparableSum::CongSeparableSum(
        size_t n_functions,
        std::vector<size_t> splitting,
        std::vector<Function*> functions)
: Function(),
m_n_functions(n_functions),
m_splitting(splitting),
m_functions(functions) {

}

CongSeparableSum::~CongSeparableSum() {
}

int CongSeparableSum::call(Matrix& x, double& f) {
    for (size_t i = 0; i < m_n_functions; i++) {
        // use shallow vector
    }
    return ForBESUtils::STATUS_OK;
}


