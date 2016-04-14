#include "TestLBFGSBuffer.h"
#include "LBFGSBuffer.h"
#include <iostream>
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(TestLBFGSBuffer);

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

    const double H0orig = 12.0;
    double H0 = H0orig;
    buffer->update(&q, &r, H0);
    _ASSERT_NUM_EQ(H0orig, H0, 1e-6);

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
                    _ASSERT_NUM_EQ(H0orig, H0, 1e-6);
                    _ASSERT_NUM_EQ(0.0, (*alpha)[1], 1e-9);
                    _ASSERT_NUM_EQ(0.0, (*alpha)[2], 1e-9);
                } else if (i == 1) {
                    _ASSERT_NUM_EQ(0.0, (*alpha)[2], 1e-9);
                }
            } else {
                _ASSERT(std::fabs(H0 - H0orig) > 0.1);
            }
            _ASSERT(r.norm_fro_sq() > 0.1);
        }
    }

    buffer->update(&q, &r, H0);
    const double H0_expected = 1.07504783819171;
    _ASSERT_NUM_EQ(H0_expected, H0, 1e-7);

    delete buffer;
}