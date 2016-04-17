/*
 * File:   TestFBProblem.cpp
 * Author: Pantelis Sopasakis
 *
 * Created on Apr 17, 2016, 12:25:58 PM
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

#include "TestFBProblem.h"
#include "Function.h"
#include "Quadratic.h"
#include "Norm1.h"
#include "MatrixOperator.h"
#include "FBProblem.h"
#include "ForBES.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TestFBProblem);

TestFBProblem::TestFBProblem() {
}

TestFBProblem::~TestFBProblem() {
}

void TestFBProblem::setUp() {
}

void TestFBProblem::tearDown() {
}

void TestFBProblem::testConstruct() {
    const size_t n = 10;
    Function * f = new Quadratic();
    Function * g = new Norm1();
    Matrix A = MatrixFactory::MakeRandomMatrix(n, n, 0.0, 1.0);
    LinearOperator * L = new MatrixOperator(A);

    FBProblem * prob = new FBProblem(*f, *L, *g);

    _ASSERT(L == prob->L1());
    _ASSERT(NULL == prob->L2());
    _ASSERT(NULL == prob->d2());
    _ASSERT(NULL == prob->d1());
    _ASSERT(NULL == prob->lin());
    _ASSERT(f == prob->f1());
    _ASSERT(NULL == prob->f2());
    _ASSERT(g == prob->g());

    delete prob;
    delete L;
    delete f;
    delete g;
}


