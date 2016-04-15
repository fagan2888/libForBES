#include "TestLBFGSBuffer.h"
#include "LBFGSBuffer.h"
#include <iostream>
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(TestLBFGSBuffer);
#define DOUBLES_EQUAL_DELTA 1e-8

TestLBFGSBuffer::TestLBFGSBuffer() {
}

TestLBFGSBuffer::~TestLBFGSBuffer() {
}

void TestLBFGSBuffer::setUp() {
}

void TestLBFGSBuffer::tearDown() {
}

void TestLBFGSBuffer::testPush1() {
    size_t n = 10;
    size_t mem = 3;
    LBFGSBuffer * buffer = new LBFGSBuffer(n, mem);

    Matrix y(n, 1);
    Matrix s(n, 1);

    for (size_t j = 0; j < n; j++) {
        y[j] = 1.0;
        s[j] = -1.0;
    }

    for (size_t i = 0; i < 10; i++) {
        int status;
        y *= 2.0;
        s *= -1.0;
        status = buffer->push(&s, &y);
        _ASSERT(ForBESUtils::is_status_ok(status));

        // check whether current sk is correctly buffered
        Matrix * buffS = buffer->get_S();
        Matrix s_curr = MatrixFactory::ShallowSubVector(*buffS, buffer->get_k_minus_j(0));
        _ASSERT_EQ(s_curr, s);

        // check whether current yk is correctly buffered
        Matrix * buffY = buffer->get_Y();
        Matrix curry = MatrixFactory::ShallowSubVector(*buffY, buffer->get_k_minus_j(0));
        _ASSERT_EQ(curry, y);

        Matrix sy = s*y;
        _ASSERT_NUM_EQ(sy[0], buffer->get_Ys()->get(buffer->get_k_minus_j(0), 0), 1e-9);
    }

    delete buffer;
}

void TestLBFGSBuffer::testPush2() {
    size_t n = 30;
    size_t mem = 3;
    LBFGSBuffer * buffer = new LBFGSBuffer(n, mem);

    Matrix y1 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix y2 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix y3 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix y4 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);

    Matrix s1 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix s2 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix s3 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix s4 = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);

    buffer->push(&s1, &y1);
    buffer->push(&s2, &y2);
    buffer->push(&s3, &y3);
    buffer->push(&s4, &y4);

    Matrix * buffS = buffer->get_S();
    Matrix s_temp = MatrixFactory::ShallowSubVector(*buffS, buffer->get_k_minus_j(0));
    _ASSERT_EQ(s4, s_temp);

    s_temp = MatrixFactory::ShallowSubVector(*buffS, buffer->get_k_minus_j(1));
    _ASSERT_EQ(s3, s_temp);

    s_temp = MatrixFactory::ShallowSubVector(*buffS, buffer->get_k_minus_j(2));
    _ASSERT_EQ(s2, s_temp);

    Matrix sy3 = s3*y3;
    Matrix sy2 = s2*y2;
    _ASSERT_NUM_EQ(sy2[0], buffer->get_Ys()->get(buffer->get_k_minus_j(2), 0), 1e-8);
    _ASSERT_NUM_EQ(sy3[0], buffer->get_Ys()->get(buffer->get_k_minus_j(1), 0), 1e-8);

    for (size_t j = 3; j < 10; j++)
        _ASSERT_EQ(LBFGSBuffer::LBFGS_BUFFER_EOB, buffer->get_k_minus_j(j));

    delete buffer;
}

void TestLBFGSBuffer::testUpdate() {
    std::srand(static_cast<unsigned long> (1433291l));

    size_t n = 10;
    size_t mem = 3;
    LBFGSBuffer * buffer = new LBFGSBuffer(n, mem);

    Matrix q = MatrixFactory::MakeRandomMatrix(n, 1, 0.0, 1.0);
    Matrix r;

    double H0 = 1.0;
    buffer->update(&q, &r, H0);

    // the value of Hk0 does not depend of the whole history stored in the
    // buffer - it only depends on y_{k-1} and s_{k-}
    for (size_t j = 0; j < 2; j++) {
        for (size_t i = 0; i < 2; i++) {
            double m = (j == 0)
                    ? 12.34
                    : ((i == 2) ? 45.33 : 0.0);
            Matrix yi = MatrixFactory::MakeRandomMatrix(n, 1, m, 1.0);
            Matrix si = MatrixFactory::MakeRandomMatrix(n, 1, m, 1.0);
            buffer->push(&si, &yi);
            buffer->update(&q, &r, H0);
            if (j == 0) {
                Matrix * alpha = buffer -> get_alphas();
                if (i == 0) {
                    _ASSERT_NUM_EQ(0.0, (*alpha)[1], 1e-9);
                    _ASSERT_NUM_EQ(0.0, (*alpha)[2], 1e-9);
                } else if (i == 1) {
                    _ASSERT_NUM_EQ(0.0, (*alpha)[2], 1e-9);
                }
            }
            _ASSERT(r.norm_fro_sq() > 0.1);
        }
    }

    delete buffer;
}

void TestLBFGSBuffer::testTwoLoopQuadratic() {
    size_t n = 10;
    int status;
    double dirs[][10] = {
        {-3.476000000000000e+01, -1.367700000000000e+01, 2.961000000000000e+00, 3.756000000000000e+00, -5.618000000000001e+00,
            -1.571000000000000e+00, -4.121000000000000e+00, -3.709000000000000e+00, 4.010000000000000e-01, 7.639999999999999e+00},
        {-6.861170733797232e-01, -1.661270665201917e+00, 2.217225828759783e-01, 5.615134140894827e-01, -1.922426760799171e-01,
            -8.961101045874649e-02, -3.044802963260585e-01, -1.996235459345302e-01, 1.267604425710271e-01, 3.360845247013288e-01},
        {-1.621334774299757e-01, 2.870743130038509e-01, -5.485761164147890e-01, 9.992734938824946e-02, -1.332550298134261e-02,
            5.326252573648004e-02, -6.299408068289099e-02, 1.525398352758627e-02, -7.776943954825605e-02, -2.335884953507601e-02},
        {-2.008976150849174e-01, 2.237224648542355e-01, 4.811889625788790e-02, -6.855884193567087e-01, -2.729265954345345e-02,
            3.651730112313705e-02, 6.325330777317102e-02, 2.871281112230844e-02, -1.285590864125103e-01, -3.204963735369064e-03},
        {-2.317011191832649e-01, 2.980080835636925e-02, -1.267017945785352e-01, 4.328230970765579e-02, -2.437461022925741e-01,
            1.349716200511426e-02, -7.155992987801446e-04, -3.513449694839539e-03, -5.603489763638486e-02, 5.612114259243500e-02}
    };

    double data_Q[] = {32.0000, 13.1000, -4.9000, -3.0000, 6.0000, 2.2000, 2.6000, 3.4000, -1.9000, -7.5000,
        13.1000, 18.3000, -5.3000, -9.5000, 3.0000, 2.1000, 3.9000, 3.0000, -3.6000, -4.4000,
        -4.9000, -5.3000, 7.7000, 2.1000, -0.4000, -3.4000, -0.8000, -3.0000, 5.3000, 5.5000,
        -3.0000, -9.5000, 2.1000, 20.1000, 1.1000, 0.8000, -12.4000, -2.5000, 5.5000, 2.1000,
        6.0000, 3.0000, -0.4000, 1.1000, 3.8000, 0.6000, 0.5000, 0.9000, -0.4000, -2.0000,
        2.2000, 2.1000, -3.4000, 0.8000, 0.6000, 7.8000, 2.9000, -1.3000, -4.3000, -5.1000,
        2.6000, 3.9000, -0.8000, -12.4000, 0.5000, 2.9000, 14.5000, 1.7000, -4.9000, 1.2000,
        3.4000, 3.0000, -3.0000, -2.5000, 0.9000, -1.3000, 1.7000, 6.6000, -0.8000, 2.7000,
        -1.9000, -3.6000, 5.3000, 5.5000, -0.4000, -4.3000, -4.9000, -0.8000, 7.9000, 5.7000,
        -7.5000, -4.4000, 5.5000, 2.1000, -2.0000, -5.1000, 1.2000, 2.7000, 5.7000, 16.1000};

    double data_xs[][10] = {
        {1.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09},
        {0.09, 1.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08},
        {0.08, 0.09, 1.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07},
        {0.07, 0.08, 0.09, 1.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06},
        {0.06, 0.07, 0.08, 0.09, 1.0, 0.01, 0.02, 0.03, 0.04, 0.05}
    };

    double data_q[] = {2.9000, 0.8000, 1.3000, -1.1000, -0.5000, -0.3000, 1.0000, -0.3000, 0.7000, -2.1000};

    size_t mem = 3;

    LBFGSBuffer * buffer = new LBFGSBuffer(n, mem);
    Matrix * Q = new Matrix(n, n, data_Q);
    Matrix * q = new Matrix(n, 1, data_q);

    Function * f = new Quadratic(*Q, *q);

    Matrix * y = new Matrix(n, 1);
    Matrix * s = new Matrix(n, 1);

    Matrix * x_old = new Matrix(n, 1, data_xs[0]);
    Matrix * grad_old = new Matrix(n, 1);

    Matrix * d = new Matrix(n, 1);
    Matrix * grad = new Matrix(n, 1);

    double fx;
    double gamma0 = 1.0;
    for (int i = 0; i < 5; i++) {
        Matrix x(n, 1, data_xs[i]);
        status = f->call(x, fx, *grad);
        _ASSERT(ForBESUtils::is_status_ok(status));
        if (i > 0) {
            *s = x - *x_old;
            *y = *grad - *grad_old;
            status = buffer->push(s, y);
            _ASSERT(ForBESUtils::is_status_ok(status));
            double sy = 0.0;
            double yy = 0.0;
            for (size_t l = 0; l < n; l++) {
                sy += ((*s)[l]) * ((*y)[l]);
                yy += std::pow((*y)[l], 2);
            }
            gamma0 = sy / yy;
        }
        status = buffer->update(grad, d, gamma0);
        _ASSERT(ForBESUtils::is_status_ok(status));
        for (int j = 0; j < n; j++) {
            // keep the minus sign in -d.get(j, 0), since I multiplied H 
            // times grad instead of -grad
            _ASSERT_NUM_EQ(dirs[i][j], -(*d)[j], DOUBLES_EQUAL_DELTA);
        }
        *x_old = x;
        *grad_old = *grad;
    }

    delete buffer;
    delete Q;
    delete q;
    delete f;
    delete y;
    delete s;
    delete x_old;
    delete grad_old;
    delete d;
    delete grad;
}
