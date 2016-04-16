/*
 * File:   TestCGSolver.cpp
 * Author: chung
 *
 * Created on Nov 16, 2015, 6:41:56 PM
 */

#include "TestCGSolver.h"
#include "CGSolver.h"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(TestCGSolver);

TestCGSolver::TestCGSolver() {
}

TestCGSolver::~TestCGSolver() {
}

void TestCGSolver::setUp() {
}

void TestCGSolver::tearDown() {
}

void TestCGSolver::testSolve() {
    size_t n = 800;

    Matrix b = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix A = MatrixFactory::MakeRandomMatrix(n, n, 0.0, 1.0, Matrix::MATRIX_SYMMETRIC);
    Matrix Y = MatrixFactory::MakeIdentity(n, 50.0);
    A += Y;

    Matrix ID(n, n, Matrix::MATRIX_DIAGONAL);
    for (size_t j = 0; j < n; ++j) {
        ID.set(j, j, 1 / A.get(j, j));
    }
    MatrixOperator Aop(A);
    MatrixOperator M(ID);

    size_t max_iter = n;
    const double tolerance = 1e-4;
    CGSolver solver(Aop, M, tolerance, max_iter);
    Matrix sol(n, 1);
    int status = solver.solve(b, sol);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT(solver.last_num_iter() < max_iter);
    _ASSERT(solver.last_error() < tolerance);
    _ASSERT(solver.last_num_iter() > 0);

    Matrix Asol = Aop.call(sol);
    for (size_t i = 0; i < n; i++) {
        _ASSERT_NUM_EQ(Asol[i], b[i], tolerance);
    }

}

void TestCGSolver::testSolve2() {
    size_t n = 500;

    Matrix b = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix A = MatrixFactory::MakeRandomMatrix(n, n, 0.0, 1.0, Matrix::MATRIX_SYMMETRIC);

    Matrix ID = MatrixFactory::MakeIdentity(n, 1.0);
    MatrixOperator Aop(A);
    MatrixOperator M(ID);

    size_t max_iter = 5;
    CGSolver solver(Aop, M, 1e-4, max_iter);
    Matrix sol(n, 1);
    int status = solver.solve(b, sol);
    _ASSERT_EQ(ForBESUtils::STATUS_MAX_ITERATIONS_REACHED, status);
}

void TestCGSolver::testSolveNoPredcond() {
    size_t n = 500;

    Matrix b = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix A = MatrixFactory::MakeRandomMatrix(n, n, 0.0, 1.0, Matrix::MATRIX_SYMMETRIC);

    MatrixOperator Aop(A);

    CGSolver solver(Aop);
    Matrix sol(n, 1);
    int status = solver.solve(b, sol);
    _ASSERT(ForBESUtils::is_status_ok(status));
    const double default_tolerance = 1e-4;
    _ASSERT(solver.last_error() < default_tolerance);
}

