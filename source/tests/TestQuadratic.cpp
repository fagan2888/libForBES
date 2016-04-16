/*
 * File:   TestQuadratic.cpp
 * Author: Pantelis Sopasakis
 *
 * Created on Jul 9, 2015, 4:14:39 AM
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

#include <complex>

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
    Function *quad = NULL;
    _ASSERT_OK(quad = new Quadratic(Q));
    _ASSERT_NEQ(quad, NULL);

    double f;
    _ASSERT(quad->category().defines_f());
    int info = quad -> call(x, f);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, info);

    if (quad != NULL) {
        delete quad;
    }
}

void TestQuadratic::testQuadratic2() {
    /* Test the empty constructor */
    size_t n = 8;
    const double tol = 1e-7;
    Function *F = new Quadratic(); /* Q = I, q = 0. */

    Matrix x = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0, Matrix::MATRIX_DENSE);
    x.set(0, 0, 666);
    Matrix grad;

    double fval = 0.0;
    _ASSERT(F->category().defines_f());
    _ASSERT(F->category().defines_grad());
    _ASSERT_EQ(ForBESUtils::STATUS_OK, F->call(x, fval, grad));

    const double fval_expected = static_cast<Matrix> (x * x).get(0, 0) / 2;
    _ASSERT_NUM_EQ(fval_expected, fval, tol);

    Matrix q(n, 1);
    for (size_t i = 0; i < n; ++i) {
        _ASSERT_OK(q.set(i, 0, i + 1));
    }
    _ASSERT_OK(static_cast<Quadratic*> (F)->setq(q));

    double fval_prev = fval;
    _ASSERT_EQ(ForBESUtils::STATUS_OK, F->call(x, fval, grad));
    _ASSERT_NUM_EQ(fval_prev + (q * x).get(0, 0), fval, 1e-6);

    _ASSERT_OK(delete F);
}

void TestQuadratic::testQuadratic3() {
    size_t n = 10;
    Matrix Q(n, n, Matrix::MATRIX_DENSE);
    for (size_t i = 0; i < n - 1; ++i) {
        Q.set(i, i, 1.5);
    }
    Quadratic *F = new Quadratic(Q);
    Matrix x(n, 1);
    double fval;
    _ASSERT(F->category().defines_conjugate());
    int status = F->callConj(x, fval);
    _ASSERT_EQ(ForBESUtils::STATUS_NUMERICAL_PROBLEMS, status);

    Q.set(n - 1, n - 1, 1.5);
    Q.set(1, 0, 0.1);
    Q.set(0, 1, 0.1);

    F->setQ(Q);
    _ASSERT_OK(status = F->callConj(x, fval));
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);

    Matrix q(n, 1);
    for (size_t i = 0; i < n; ++i) {
        q.set(i, 0, i + 1);
        x.set(i, 0, 2 * i + 1);
    }


    Matrix grad;
    static_cast<Quadratic*> (F)->setq(q);

    _ASSERT_OK(status = F->callConj(x, fval, grad));
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);

    const double fval_exp = 190.002976190476;
    const double tol = 1e-8;

    _ASSERT_NUM_EQ(fval_exp, fval, tol);

    double grad0_exp = -0.0446428571428572;
    _ASSERT_NUM_EQ(grad0_exp, grad.get(0, 0), tol);

    _ASSERT_OK(delete F);
}

void TestQuadratic::testCallProx() {
    Function *F = new Quadratic(); // F(x) = (1/2)x'x
    Matrix x(4, 1);
    for (size_t i = 0; i < 4; i++) {
        x[i] = 0.34 + std::sqrt(i+0.3);
    }

    const double gamma = 0.737;
    const double tol = 1e-7;

    Matrix prox;

    _ASSERT_NOT(F->category().defines_prox());
    _ASSERT_EQ(ForBESUtils::STATUS_OK, F->callProx(x, gamma, prox));
    _ASSERT_NUM_EQ(0.511066527061120, prox[0], tol);
    _ASSERT_NUM_EQ(0.852144746746769, prox[1], tol);
    _ASSERT_NUM_EQ(1.068840005072142, prox[2], tol);
    _ASSERT_NUM_EQ(1.241560283510935, prox[3], tol);

    delete F;
}

void TestQuadratic::testCallProx2() {
    const size_t n = 3;
    double data_Q[9] = {
        0.29507822324818300, 0.00199205562668041, 0.00423436821643449,
        0.00199205562668041, 0.24650478030564038, 0.00233990839749903,
        0.00423436821643449, 0.00233990839749903, 0.27841699644617668
    };
    Matrix Q(n, n, data_Q);

    double data_q[n * n] = {0.1, 0.2, -0.3};
    Matrix q(n, 1, data_q);

    const double gamma = 0.02;

    double data_v[n] = {-1.0, 2.0, -0.5};
    Matrix v(n, 1, data_v);

    double data_prox_exp[] = {
        -0.996158636187904,
        1.986270176873906,
        -0.491273016601634
    };
    Matrix prox_exp(n, 1, data_prox_exp);

    Quadratic F(Q, q);
    Matrix prox(n, 1);
    F.callProx(v, gamma, prox);

    _ASSERT_EQ(prox_exp, prox);
}

void TestQuadratic::testCall2() {
    Function * quad = new Quadratic();
    Matrix x(4, 1);
    for (size_t i = 0; i < 4; i++) {
        x[i] = 0.1 * (i + 1.0);
    }
    double f;
    int status = quad->call(x, f);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(0.15, f, 1e-6);
    delete quad;
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

    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);
    _ASSERT_EQ(42.0, f);

    /* Second part */
    Quadratic quadratic2(Q);
    status = quadratic2.call(x, f);
    _ASSERT_EQ(0, status);
    _ASSERT_EQ(32.0, f);
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
    double f = -999.0;
    Matrix grad;
    _ASSERT(quad->category().defines_f());
    _ASSERT(quad->category().defines_grad());
    _ASSERT_EQ(ForBESUtils::STATUS_OK, quad -> call(x, f, grad));

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
    _ASSERT_EQ(ForBESUtils::STATUS_OK, quadratic.callConj(x, fstar));


    double expected = 421.0;
    const double rel_tol = 1e-5;
    _ASSERT(std::fabs(expected - fstar) / expected < rel_tol);

    for (size_t i = 0; i < n; i++) {
        x[i] = 10 + 2 * i;
    }

    _ASSERT_EQ(ForBESUtils::STATUS_OK, quadratic.callConj(x, fstar));
    expected = 3722;
    _ASSERT(std::fabs(expected - fstar) / expected < rel_tol);

    Matrix grad;

    _ASSERT_EQ(ForBESUtils::STATUS_OK, quadratic.callConj(x, fstar, grad));

    Matrix grad_expected(n, 1);
    grad_expected.set(0, 0, 45.5);
    grad_expected.set(1, 0, 35.5);
    grad_expected.set(2, 0, 96.5);
    grad_expected.set(3, 0, 188.5);

    const double tol = 1e-5;
    for (size_t i = 0; i < n; i++) {
        _ASSERT_NUM_EQ(grad_expected.get(i, 0), grad.get(i, 0), tol);
    }

}

void TestQuadratic::testCallConj2() {
    const size_t n = 4;

    double qdata[4] = {2.0, 3.0, 4.0, 5.0};
    double xdata[4] = {-1.0, 1.0, 1.0, 1.0};

    Quadratic *F = new Quadratic();
    Matrix q(n, 1, qdata);
    Matrix x(n, 1, xdata);

    _ASSERT_OK(F->setq(q));
    double fstar;
    double fstar_exp = 38.0;
    const double tol = 1e-6;

    _ASSERT_EQ(ForBESUtils::STATUS_OK, F->callConj(x, fstar));
    _ASSERT_NUM_EQ(fstar_exp, fstar, tol);
    _ASSERT_OK(delete F);

    double alpha = 2.3;
    Matrix Eye = MatrixFactory::MakeIdentity(n, alpha); /* Here Eye is a diagonal matrix */
    Function *F2 = new Quadratic(Eye, q);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, F2->callConj(x, fstar));
    _ASSERT_NUM_EQ(fstar_exp / alpha, fstar, tol);
    _ASSERT_OK(delete F2);
}

void TestQuadratic::testCallDiagonalMatrix() {
    const size_t n = 4;
    Matrix Q(n, n, Matrix::MATRIX_DIAGONAL);
    for (size_t i = 0; i < n; i++) {
        Q[i] = i + 2.0;
    }

    Function *f = new Quadratic(Q);

    Matrix x(n, 1);
    for (size_t i = 0; i < n; i++) {
        x[i] = 2 * i + 1.0;
    }

    double val;
    f -> call(x, val);

    double tol = 1e-8;
    _ASSERT_NUM_EQ(187.0, val, tol);
    _ASSERT_OK(delete f);
}

void TestQuadratic::testCallSparse() {
    /*
     * Q is sparse, x is dense
     */
    size_t n = 10;
    size_t nnz_Q = 20;
    Matrix Qsp = MatrixFactory::MakeRandomSparse(n, n, nnz_Q, 0.0, 1.0);

    Function *F = new Quadratic(Qsp);

    Matrix x = MatrixFactory::MakeRandomMatrix(n, 1, 3.0, 1.5, Matrix::MATRIX_DENSE);
    double fval = -1;
    _ASSERT_EQ(ForBESUtils::STATUS_OK, F->call(x, fval));
    _ASSERT(fval > 0);

    double f_exp = Qsp.quad(x);
    const double tol = 1e-8;
    _ASSERT_NUM_EQ(f_exp, fval, tol);

    _ASSERT_OK(delete F);

}

void TestQuadratic::testCallSparse2() {
    /*
     * BOTH Q and x are sparse
     */
    size_t n = 10;
    size_t nnz_Q = 20;
    size_t nnz_x = 6;
    Matrix Qsp = MatrixFactory::MakeRandomSparse(n, n, nnz_Q, 0.0, 1.0);

    Function *F = new Quadratic(Qsp);

    Matrix x = MatrixFactory::MakeRandomSparse(n, 1, nnz_x, 0.0, 1.0);
    double fval = -1;
    _ASSERT_EQ(ForBESUtils::STATUS_OK, F->call(x, fval));
    _ASSERT(fval > 0);

    double f_exp = Qsp.quad(x);
    const double tol = 1e-8;
    _ASSERT_NUM_EQ(f_exp, fval, tol);

    _ASSERT_OK(delete F);
}

void TestQuadratic::testCallConjSparse() {
    size_t n = 5;
    size_t nnz_Q = 2 * n - 1;
    double fstar = -1;
    const double tol = 1e-8;
    const double fstar_exp = 5.13142364727941;
    int status;
    Function *F;

    Matrix Qsp = MatrixFactory::MakeSparseSymmetric(n, nnz_Q);
    Matrix x(n, 1);

    for (size_t i = 0; i < n; i++) {
        Qsp.set(i, i, 10.0);
        x.set(i, 0, i + 1);
    }
    for (size_t i = 1; i < n; i++) { /* Set the LT part */
        Qsp.set(i, i - 1, 0.5);
    }

    F = new Quadratic(Qsp);
    _ASSERT_OK(status = F->callConj(x, fstar));
    _ASSERT_NEQ(-1, fstar);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);

    _ASSERT_NUM_EQ(fstar_exp, fstar, tol);

    _ASSERT_OK(delete F);

}

void TestQuadratic::testCallSparse3() {
    const size_t n = 10;
    const double tol = 1e-7;
    Matrix Q = MatrixFactory::MakeRandomMatrix(n, n, 0.0, 2.0, Matrix::MATRIX_SYMMETRIC);
    Matrix q = MatrixFactory::MakeSparse(n, 1, 0, Matrix::SPARSE_UNSYMMETRIC); /* q = [] */
    Matrix x = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0, Matrix::MATRIX_DENSE);

    Function *F = new Quadratic(Q, q);

    double f;
    int status = F->call(x, f);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);
    double f_exp = Q.quad(x);
    _ASSERT_NUM_EQ(f_exp, f, tol);

    q = MatrixFactory::MakeSparse(n, 1, 1, Matrix::SPARSE_UNSYMMETRIC);
    q.set(0, 0, 5.5);


    status = F->call(x, f);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);
    f_exp = Q.quad(x, q);
    _ASSERT_NUM_EQ(f_exp, f, tol);

    _ASSERT_OK(delete F);

}

void TestQuadratic::testHessian() {
    const size_t n = 4;

    Matrix Q = MatrixFactory::MakeRandomMatrix(n, n, 5.0, 1.0);
    Matrix x = MatrixFactory::MakeRandomMatrix(n, 1, 1.0, 2.0);
    Matrix d = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix Hd = Matrix(n, 1);
    Matrix Hd_reference = Matrix(n, 1);

    Function * quad = new Quadratic(Q);
    int status = Matrix::mult(Hd_reference, 1.0, Q, d, 0.0);
    _ASSERT(ForBESUtils::is_status_ok(status));
    status = quad->hessianProduct(x, d, Hd);
    _ASSERT(ForBESUtils::is_status_ok(status));

    _ASSERT_EQ(Hd, Hd_reference);

    delete quad;
}

void TestQuadratic::testHessianSparse() {
    const size_t n = 10;
    const size_t nnz = 45;

    Matrix Q = MatrixFactory::MakeRandomSparse(n, n, nnz, 5.0, 1.0);
    Matrix x = MatrixFactory::MakeRandomMatrix(n, 1, 1.0, 2.0);
    Matrix d = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix Hd = Matrix(n, 1);
    Matrix Hd_reference = Matrix(n, 1);

    Function * quad = new Quadratic(Q);
    Hd_reference = Q*d;
    int status = quad->hessianProduct(x, d, Hd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_EQ(Hd, Hd_reference);

    delete quad;
}

void TestQuadratic::testApproximateHessian() {

    const size_t n = 4;
    const double * Qdata;
    Matrix grad_x;
    double f;
    Qdata = MAT1;

    double qdata[4] = {2.0, 3.0, 4.0, 5.0};
    double xdata[4] = {-1.0, 1.0, 1.0, 1.0};

    Matrix Q = Matrix(n, n, Qdata);
    Matrix q = Matrix(n, 1, qdata);


    Quadratic quadratic(Q, q);

    Matrix x = Matrix(n, 1, xdata);
    Matrix z = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 2.0);
    const double epsilon = 1e-8;
    const double one_over_epsilon = 1e8;

    /* t = t + εz */
    Matrix t(x);
    Matrix::add(t, epsilon, z, 1.0);


    Matrix Hz(n, 1);
    quadratic.call(t, f, Hz); /* Hz = nabla f(t)              */
    quadratic.call(x, f, grad_x); /* grad_x = nabla f(x)          */
    Hz -= grad_x; /* Hz = nabla f(t) - nabla f(x) */
    Hz *= one_over_epsilon;

    Matrix Hz_copy = Hz;

    quadratic.hessianProduct(x, z, Hz);

    for (size_t i = 0; i < n; i++) {
        _ASSERT_NUM_EQ(Hz_copy[i], Hz[i], 1e-6);
    }
}


