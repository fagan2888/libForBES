#include "TestLBFGSBuffer.h"
#include "LBFGSBuffer.h"
#include <iostream>

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
    size_t n = 10;
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

void TestLBFGSBuffer::testTwoLoopQuadratic() {
    size_t n = 10;

    double dirs[][10] = { {-6.861170733797231e-01,-1.661270665201917e+00,2.217225828759783e-01,5.615134140894827e-01,-1.922426760799170e-01,
                            -8.961101045874648e-02,-3.044802963260585e-01,-1.996235459345302e-01,1.267604425710271e-01,3.360845247013287e-01},
                        {-1.621334774299757e-01,2.870743130038509e-01,-5.485761164147890e-01,9.992734938824946e-02,-1.332550298134261e-02,
                            5.326252573648004e-02,-6.299408068289099e-02,1.525398352758627e-02,-7.776943954825605e-02,-2.335884953507601e-02},
                        {-2.008976150849174e-01,2.237224648542355e-01,4.811889625788801e-02,-6.855884193567087e-01,-2.729265954345344e-02,
                            3.651730112313704e-02,6.325330777317101e-02,2.871281112230844e-02,-1.285590864125103e-01,-3.204963735369066e-03},
                        {-2.317011191832649e-01,2.980080835636925e-02,-1.267017945785352e-01,4.328230970765576e-02,-2.437461022925741e-01,
                            1.349716200511426e-02,-7.155992987801457e-04,-3.513449694839540e-03,-5.603489763638487e-02,5.612114259243502e-02} }; 

    double data_Q[] = { 32.0000,13.1000,-4.9000,-3.0000,6.0000,2.2000,2.6000,3.4000,-1.9000,-7.5000,
                        13.1000,18.3000,-5.3000,-9.5000,3.0000,2.1000,3.9000,3.0000,-3.6000,-4.4000,
                        -4.9000,-5.3000,7.7000,2.1000,-0.4000,-3.4000,-0.8000,-3.0000,5.3000,5.5000,
                        -3.0000,-9.5000,2.1000,20.1000,1.1000,0.8000  -12.4000,-2.5000,5.5000,2.1000,
                        6.0000,3.0000,-0.4000,1.1000,3.8000,0.6000,0.5000,0.9000,-0.4000,-2.0000,
                        2.2000,2.1000,-3.4000,0.8000,0.6000,7.8000,2.9000,-1.3000,-4.3000,-5.1000,
                        2.6000,3.9000,-0.8000  -12.4000,0.5000,2.9000,14.5000,1.7000,-4.9000,1.2000,
                        3.4000,3.0000,-3.0000,-2.5000,0.9000,-1.3000,1.7000,6.6000,-0.8000,2.7000,
                        -1.9000,-3.6000,5.3000,5.5000,-0.4000,-4.3000,-4.9000,-0.8000,7.9000,5.7000,
                        -7.5000,-4.4000,5.5000,2.1000,-2.0000,-5.1000,1.2000,2.7000,5.7000, 16.1000};

    double data_xs[][10] = { {1.0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09},
                            {0.09,1.0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08},
                            {0.08,0.09,1.0,0.01,0.02,0.03,0.04,0.05,0.06,0.07},
                            {0.07,0.08,0.09,1.0,0.01,0.02,0.03,0.04,0.05,0.06},
                            {0.06,0.07,0.08,0.09,1.0,0.01,0.02,0.03,0.04,0.05} };

    double data_q[] = {2.9000,0.8000,1.3000,-1.1000,-0.5000,-0.3000,1.0000,-0.3000,0.7000,-2.1000};

    size_t mem = 3;

    LBFGSBuffer * buffer = new LBFGSBuffer(n, mem);
    Matrix * Q = new Matrix(n, n, data_Q);

    // std::cout << std::endl << *Q << std::endl;

    Matrix * q = new Matrix(n, 1, data_q);

    // std::cout << std::endl << *q << std::endl;

    Function * f = new Quadratic(*Q, *q);

    Matrix * y = new Matrix(n, 1);
    Matrix * s = new Matrix(n, 1);

    Matrix * x_old = new Matrix(n, 1, data_xs[0]);
    Matrix * grad_old = new Matrix(n, 1);

    Matrix * d = new Matrix(n, 1);
    Matrix * grad = new Matrix(n, 1);

    double fx;

    f->call(*x_old, fx, *grad_old);

    for (int i=1; i<=4; i++) {
        Matrix * x = new Matrix(n, 1, data_xs[i]);
        f->call(*x, fx, *grad);
        (*s) = (*x)-(*x_old);
        (*y) = (*grad)-(*grad_old);
        buffer->push(s, y);
        buffer->update(grad, d);
        for (int j=0; j<n; j++) {
            // keep the minus sign in -d.get(j, 0), since I multiplied H times grad instead of -grad
            CPPUNIT_ASSERT_DOUBLES_EQUAL(dirs[i-1][j], -d->get(j, 0), DOUBLES_EQUAL_DELTA);
        }
        (*x_old) = (*x);
        (*grad_old) = (*grad);
        delete x;
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
