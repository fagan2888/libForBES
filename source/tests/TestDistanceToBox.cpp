/*
 * File:   TestDistanceToBox.cpp
 * Author: Pantelis Sopasakis
 *
 * Created on Oct 28, 2015, 7:28:27 PM
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

#include "TestDistanceToBox.h"
#include "DistanceToBox.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TestDistanceToBox);

TestDistanceToBox::TestDistanceToBox() {
}

TestDistanceToBox::~TestDistanceToBox() {
}

void TestDistanceToBox::setUp() {
    std::srand(time(NULL));
}

void TestDistanceToBox::tearDown() {
}

void TestDistanceToBox::testCall() {

    Matrix LB(2, 1);
    Matrix UB(2, 1);

    LB[0] = -1.0;
    UB[0] = 1.0;

    LB[1] = -2.0;
    UB[1] = 5.0;

    Matrix weights(2, 1);
    weights[0] = 0.5;
    weights[1] = 2.0;

    Function * d2b = new DistanceToBox(&LB, &UB, &weights);

    Matrix x(2, 1);
    x[0] = -1.5;
    x[1] = 6;

    double f;
    double f2;
    Matrix grad(2, 1);
    _ASSERT(d2b->category().defines_f());
    _ASSERT(d2b->category().defines_grad());
    int status = d2b->call(x, f, grad);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);
    status = d2b->call(x, f2);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);

    const double tol = 1e-12;
    _ASSERT_NUM_EQ(f, f2, tol);
    _ASSERT_NUM_EQ(1.06250, f, tol);
    _ASSERT_NUM_EQ(-0.25, grad[0], tol);
    _ASSERT_NUM_EQ(2.0, grad[1], tol);

    delete d2b;
}

void TestDistanceToBox::testCall2() {
    Matrix LB(2, 1);
    Matrix UB(2, 1);
    LB[0] = -1.0;
    UB[0] = 1.0;
    LB[1] = -2.0;
    UB[1] = 5.0;

    double w = 10.5;
    Matrix W(2, 1);
    W[0] = w;
    W[1] = w;

    Function * d2b = new DistanceToBox(&LB, &UB, w);
    Function * d2b_ = new DistanceToBox(&LB, &UB, &W);

    Matrix x(2, 1);
    x[0] = -1.5;
    x[1] = 6;

    double f, f2;
    const double tol = 1e-12;

    Matrix grad(2, 1);
    Matrix grad2(2, 1);
    _ASSERT(d2b->category().defines_f());
    _ASSERT(d2b->category().defines_grad());
    int status = d2b->call(x, f, grad);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, d2b_ ->call(x, f2, grad2));
    _ASSERT_NUM_EQ(f, f2, tol);
    _ASSERT_EQ(grad, grad2);

    delete d2b;
    delete d2b_;
}

void TestDistanceToBox::testCall3() {
    double lb = -1.1;
    double ub = 1.2;
    double w = 0.985;
    Function * db = new DistanceToBox(lb, ub, w);

    const size_t n = 10;

    Matrix lb_vec(n, 1);
    Matrix ub_vec(n, 1);
    Matrix w_vec(n, 1);

    for (size_t i = 0; i < n; i++) {
        lb_vec[i] = lb;
        ub_vec[i] = ub;
        w_vec[i] = w;
    }

    Function * db_ = new DistanceToBox(&lb_vec, &ub_vec, &w_vec);

    const double tol = 1e-12;

    for (size_t r = 0; r < 50; r++) {
        double f;
        double f_;
        int status;
        Matrix x = MatrixFactory::MakeRandomMatrix(n, 1, -1.0, 2.0);
        status = db->call(x, f);
        _ASSERT(ForBESUtils::is_status_ok(status));
        status = db_->call(x, f_);
        _ASSERT(ForBESUtils::is_status_ok(status));
        _ASSERT_NUM_EQ(f, f_, tol);

    }

}

