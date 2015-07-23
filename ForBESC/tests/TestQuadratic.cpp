/*
 * File:   TestQuadratic.cpp
 * Author: chung
 *
 * Created on Jul 9, 2015, 4:14:39 AM
 */

#include "TestQuadratic.h"


const static double MAT1[16] = {
    7, 2, -2, -1,
    2, 3, 0, -1,
    -2, 0, 3, -1,
    -1, -1, -1, 1
};
const static double MAT2[16] = {
    16.0, 2.0, 3.0, 13.0,
    5.0, 11.0, 10.0, 8.0,
    9.0, 7.0, 6.0, 12.0,
    4.0, 14.0, 15.0, 1.0
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestQuadratic);

TestQuadratic::TestQuadratic() {
}

TestQuadratic::~TestQuadratic() {
}

void TestQuadratic::setUp() {
}

void TestQuadratic::tearDown() {
}

void TestQuadratic::testQuadratic() {
    const double * Qdata;
    Qdata = MAT2;
    double xdata[4] = {-1.0, 1.0, 1.0, 1.0};

    Matrix Q = Matrix(4, 4, Qdata);
    Matrix x = Matrix(4, 1, xdata);
    Function *quad = new Quadratic(Q);

    double f;
    int info = quad -> call(x, f);
    _ASSERT_EQ(Function::STATUS_OK, info);

    delete quad;
}

void TestQuadratic::testQuadratic2() {
    //  CPPUNIT_ASSERT(false);
}

void TestQuadratic::testQuadratic3() {
    //  CPPUNIT_ASSERT(false);
}

void TestQuadratic::testQuadratic4() {
    //   CPPUNIT_ASSERT(false);
}

void TestQuadratic::testCall() {
    const double * Qdata;
    Qdata = MAT2;
    double qdata[4] = {2.0, 3.0, 4.0, 5.0};
    double xdata[4] = {-1.0, 1.0, 1.0, 1.0};

    Matrix Q = Matrix(4, 4, Qdata);
    Matrix q = Matrix(4, 1, qdata);
    Matrix x = Matrix(4, 1, xdata);

    Quadratic quadratic(Q, q);
    double f = -999.0;
    int status = quadratic.call(x, f);

    _ASSERT_EQ(Function::STATUS_OK, status);
    _ASSERT_EQ(74.0, f);

    /* Second part */
    Quadratic quadratic2(Q);
    status = quadratic2.call(x, f);
    _ASSERT_EQ(0, status);
    _ASSERT_EQ(64.0, f);
}

void TestQuadratic::testCallWithGradient() {
    const size_t n = 4;
    const double * Qdata;
    Qdata = MAT1;
    double xdata[4] = {-1.0, 1.0, 1.0, 1.0};
    const double expected[4] = {-8, 0, 4, 0};

    Matrix Q = Matrix(n, n, Qdata);
    Matrix x = Matrix(n, 1, xdata);

    Function * quad = new Quadratic(Q);
    double f = -999.0f;
    Matrix grad;
    _ASSERT_EQ(Function::STATUS_OK, quad -> call(x, f, grad));

    for (size_t i = 0; i < n; i++) {
        _ASSERT_EQ(expected[i], grad[i]);
    }

    delete quad;

}

void TestQuadratic::testCallConj() {
    const size_t n = 4;
    const double * Qdata;
    Qdata = MAT1;

    double qdata[4] = {2.0, 3.0, 4.0, 5.0};
    double xdata[4] = {-1.0, 1.0, 1.0, 1.0};

    Matrix Q = Matrix(n, n, Qdata);
    Matrix q = Matrix(n, 1, qdata);
    Matrix x = Matrix(n, 1, xdata);

    Quadratic quadratic(Q, q);
    double fstar;
    quadratic.callConj(x, fstar);

    double expected = 421.0;
    _ASSERT(std::fabs(expected - fstar) / expected < 1e-5);

    for (size_t i = 0; i < n; i++) {
        x[i] = 10 + 2 * i;
    }

    quadratic.callConj(x, fstar);
    expected = 3722;
    _ASSERT(std::fabs(expected - fstar) / expected < 1e-5);
}

void TestQuadratic::testCategory() {
    Quadratic quadratic;
    int cat = quadratic.category();
    _ASSERT_EQ(Function::CAT_QUADRATIC, cat);
}

void TestQuadratic::testCallDiagonalMatrix() {
    const size_t n = 4;
    Matrix Q(n, n, Matrix::MATRIX_DIAGONAL);
    for (size_t i = 0; i < n; i++) {
        Q[i] = i + 2.0f;
    }

    Function *f = new Quadratic(Q);

    Matrix x(n, 1);
    for (size_t i = 0; i < n; i++) {
        x[i] = 2 * i + 1.0f;
    }

    double val;
    f -> call(x, val);

    double tol = 1e-8;
    _ASSERT_NUM_EQ(374, val, tol);
}