#include <complex>

#include "FBCache.h"
#include "FBProblem.h"

#include "TestFBCache.h"

#define DOUBLES_EQUAL_DELTA 1e-8

CPPUNIT_TEST_SUITE_REGISTRATION(TestFBCache);

TestFBCache::TestFBCache() {
}

TestFBCache::~TestFBCache() {
}

void TestFBCache::setUp() {
}

void TestFBCache::tearDown() {
}

void TestFBCache::testBoxQP_small() {
    size_t n = 4;
    // problem data
    double data_Q[] = {
        7, 2, -2, -1,
        2, 3, 0, -1,
        -2, 0, 3, -1,
        -1, -1, -1, 1
    };
    double data_q[] = {
        1, 2, 3, 4
    };
    double gamma1 = 0.1;
    double gamma2 = 0.2;
    double lb = -1;
    double ub = +1;
    // starting points
    double data_x1[] = {+0.5, +1.2, -0.7, -1.1};
    double data_x2[] = {-1.0, -1.0, -1.0, -1.0};
    // reference results 1
    double ref_fx1 = +3.774999999999999;
    double ref_y1_g01[] = {-0.44, +0.43, -0.80, -1.29};
    double ref_z1_g01[] = {-0.44, +0.43, -0.80, -1.00};
    double ref_y1_g02[] = {-1.38, -0.34, -0.90, -1.48};
    double ref_z1_g02[] = {-1.00, -0.34, -0.90, -1.00};
    double ref_FBEx1_g01 = -3.417500000000000;
    double ref_FBEx1_g02 = -10.514000000000003;
    /*
     * WARNING: The following two arrays are never used
     */
    double ref_gradFBEx1_g01[] = {1.379999999999999, 3.409999999999999, 2.480000000000000, 0.909999999999999};
    double ref_gradFBEx1_g02[] = {-5.779999999999999, -0.020000000000000, 3.300000000000000, 2.840000000000000};

    // reference results 2
    double ref_fx2 = -6.000000000000000;
    double ref_y2_g01[] = {-0.50, -0.80, -1.30, -1.60};
    double ref_z2_g01[] = {-0.50, -0.80, -1.00, -1.00};
    double ref_y2_g02[] = {+0.00, -0.60, -1.60, -2.20};
    double ref_z2_g02[] = {+0.00, -0.60, -1.00, -1.00};
    double ref_FBEx2_g01 = -7.450000000000000;
    double ref_FBEx2_g02 = -8.900000000000000;

    Matrix Q(n, n, data_Q);
    Matrix q(n, 1, data_q);
    Quadratic f(Q, q);
    IndBox g(lb, ub);
    FBProblem prob(f, g);

    FBCache * cache;
    Matrix * x, * y, * z, * gradFBEx;
    double fx, FBEx;

    // test FB operations starting from x1
    x = new Matrix(n, 1, data_x1);
    cache = new FBCache(prob, *x, 1.0);
    fx = cache->get_eval_f();
    _ASSERT_EQ(FBCache::STATUS_EVALF, cache->cache_status());
    y = cache->get_forward_step(gamma1);
    _ASSERT_EQ(FBCache::STATUS_FORWARD, cache->cache_status());
    z = cache->get_forward_backward_step(gamma1);
    _ASSERT_EQ(FBCache::STATUS_FORWARDBACKWARD, cache->cache_status());
    FBEx = cache->get_eval_FBE(gamma1);
    _ASSERT_EQ(FBCache::STATUS_FBE, cache->cache_status());
    gradFBEx = cache->get_grad_FBE(gamma1);
    _ASSERT_EQ(FBCache::STATUS_GRAD_FBE, cache->cache_status());

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g01[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g01[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
        // CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_gradFBEx1_g01[i], gradFBEx->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g01, FBEx, DOUBLES_EQUAL_DELTA);

    // change gamma
    y = cache->get_forward_step(gamma2);
    _ASSERT_EQ(FBCache::STATUS_FORWARD, cache->cache_status());
    z = cache->get_forward_backward_step(gamma2);
    _ASSERT_EQ(FBCache::STATUS_FORWARDBACKWARD, cache->cache_status());
    FBEx = cache->get_eval_FBE(gamma2);
    _ASSERT_EQ(FBCache::STATUS_FBE, cache->cache_status());
    gradFBEx = cache->get_grad_FBE(gamma2);
    _ASSERT_EQ(FBCache::STATUS_GRAD_FBE, cache->cache_status());

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g02[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g02[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
        // CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_gradFBEx1_g02[i], gradFBEx->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g02, FBEx, DOUBLES_EQUAL_DELTA);

    delete x;

    // change point x
    x = new Matrix(n, 1, data_x2);
    cache->set_point(*x);
    _ASSERT_EQ(FBCache::STATUS_NONE, cache->cache_status());
    fx = cache->get_eval_f();
    y = cache->get_forward_step(gamma1);
    z = cache->get_forward_backward_step(gamma1);
    FBEx = cache->get_eval_FBE(gamma1);
    gradFBEx = cache->get_grad_FBE(gamma1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx2, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y2_g01[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z2_g01[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx2_g01, FBEx, DOUBLES_EQUAL_DELTA);

    // change gamma
    y = cache->get_forward_step(gamma2);
    z = cache->get_forward_backward_step(gamma2);
    FBEx = cache->get_eval_FBE(gamma2);
    gradFBEx = cache->get_grad_FBE(gamma2);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx2, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y2_g02[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z2_g02[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx2_g02, FBEx, DOUBLES_EQUAL_DELTA);

    delete x;
    delete cache;
}

void TestFBCache::testSparseLeastSquares_small() {
    size_t n = 10;
    size_t m = 5;
    // problem data
    double data_A[] = {
        4, -5, 0, -3, 1,
        -4, 2, 3, 8, -1,
        -11, -5, 6, -6, 4,
        0, 7, -10, -1, -7,
        14, 4, 6, -6, -3,
        -2, 5, -2, 3, -11,
        -2, -5, -8, 2, 1,
        0, -7, 5, 1, -2,
        0, -2, -9, -2, -5,
        -5, -6, -3, -11, 4
    };
    double data_minusb[] = {1, 4, -6, 2, 3};
    double gamma1 = 0.0017;
    double gamma2 = 0.003;
    // starting points
    double data_x1[] = {-0.14, -0.24, -0.15, 0.03, 0.03, 0.04, -0.02, 0.01, -0.05, 0.08};
    double data_x2[] = {-0.14, 0.04, -0.09, -0.04, 0.05, 0.10, -0.12, 0.12, 0.06, -0.01};
    // reference results 1
    double ref_fx1 = 47.978750000000005;
    double ref_y1_g1[] = {-0.118172, -0.202073, 0.015444, -0.128984, 0.015125, 0.021640, -0.072156, 0.141121, -0.124545, 0.114323};
    double ref_z1_g1[] = {-0.116472, -0.200373, 0.013744, -0.127284, 0.013425, 0.019940, -0.070456, 0.139421, -0.122845, 0.112623};
    double ref_y1_g2[] = {-0.10148, -0.17307, 0.14196, -0.25056, 0.00375, 0.00760, -0.11204, 0.24139, -0.18155, 0.14057};
    double ref_z1_g2[] = {-0.09848, -0.17007, 0.13896, -0.24756, 0.00075, 0.00460, -0.10904, 0.23839, -0.17855, 0.13757};
    double ref_FBEx1_g1 = 24.874158335000004;
    double ref_FBEx1_g2 = 6.877117650000010;
    // reference results 2
    double ref_fx2 = 33.691600000000001;
    double ref_y2_g1[] = {-0.093607, 0.018614, 0.070837, -0.171631, 0.050833, 0.043475, -0.145942, 0.222323, 0.021240, 0.091524};
    double ref_z2_g1[] = {-0.091907, 0.016914, 0.069137, -0.169931, 0.049133, 0.041775, -0.144242, 0.220623, 0.019540, 0.089824};
    double ref_y2_g2[] = {-0.05813, 0.00226, 0.19383, -0.27229, 0.05147, 0.00025, -0.16578, 0.30057, -0.00840, 0.16916};
    double ref_z2_g2[] = {-0.05513, 0, 0.19083, -0.26929, 0.04847, 0, -0.16278, 0.29757, -0.00540, 0.16616};
    double ref_FBEx2_g1 = 13.450436129999996;
    double ref_FBEx2_g2 = -2.445831616666666;

    Matrix A(m, n, data_A);
    Matrix minusb(m, 1, data_minusb);
    MatrixOperator OpA(A);
    QuadraticLoss f;
    Norm1 g;
    FBProblem prob(f, OpA, minusb, g);

    FBCache * cache;
    Matrix * x, * y, * z, * gradFBEx;
    double fx, FBEx;

    // test FB operations starting from x1
    x = new Matrix(n, 1, data_x1);
    cache = new FBCache(prob, *x, 1.0);
    fx = cache->get_eval_f();
    y = cache->get_forward_step(gamma1);
    z = cache->get_forward_backward_step(gamma1);
    FBEx = cache->get_eval_FBE(gamma1);
    gradFBEx = cache->get_grad_FBE(gamma1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g1[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g1[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g1, FBEx, DOUBLES_EQUAL_DELTA);

    // change gamma
    y = cache->get_forward_step(gamma2);
    z = cache->get_forward_backward_step(gamma2);
    FBEx = cache->get_eval_FBE(gamma2);
    gradFBEx = cache->get_grad_FBE(gamma2);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g2[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g2[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g2, FBEx, DOUBLES_EQUAL_DELTA);

    delete x;

    // test FB operations starting from x2
    x = new Matrix(n, 1, data_x2);
    cache->set_point(*x);
    fx = cache->get_eval_f();
    y = cache->get_forward_step(gamma1);
    z = cache->get_forward_backward_step(gamma1);
    FBEx = cache->get_eval_FBE(gamma1);
    gradFBEx = cache->get_grad_FBE(gamma1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx2, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y2_g1[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z2_g1[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx2_g1, FBEx, DOUBLES_EQUAL_DELTA);

    // change gamma
    y = cache->get_forward_step(gamma2);
    z = cache->get_forward_backward_step(gamma2);
    FBEx = cache->get_eval_FBE(gamma2);
    gradFBEx = cache->get_grad_FBE(gamma2);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx2, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y2_g2[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z2_g2[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx2_g2, FBEx, DOUBLES_EQUAL_DELTA);

    delete x;
    delete cache;
}

void TestFBCache::testSparseLogReg_small() {
    size_t n = 5;
    size_t m = 4;
    // problem data
    double data_A[] = {
        1, 2, -1, -1,
        -2, -1, 0, -1,
        3, 0, 4, -1,
        -4, -1, -3, 1,
        5, 3, 2, 3
    };
    double data_minusb[] = {
        -1, 1, -1, 1
    };
    double gamma1 = 0.1;
    double gamma2 = 0.05;
    // starting points
    double data_x1[] = {0, 0, 0, 0, 0};
    // reference results
    double ref_fx1 = 3.253046750072892;
    double ref_y1_g1[] = {0.026894142137000, -0.200000000000000, 0.484846862904004, -0.511741005041004, 0.673105857863000};
    double ref_z1_g1[] = {0, -0.100000000000000, 0.384846862904004, -0.411741005041004, 0.573105857863001};
    double ref_FBEx1_g1 = -0.027393687107681;
    double ref_y1_g2[] = {0.013447071068500, -0.100000000000000, 0.242423431452002, -0.255870502520502, 0.336552928931500};
    double ref_z1_g2[] = {0, -0.050000000000000, 0.192423431452002, -0.205870502520502, 0.286552928931500};
    double ref_FBEx1_g2 = 1.612826531482605;

    Matrix A(m, n, data_A);
    Matrix minusb(m, 1, data_minusb);
    Matrix xstar;
    LogLogisticLoss f(1.0);
    MatrixOperator OpA(A);
    Norm1 g(1.0);
    FBProblem prob(f, OpA, minusb, g);

    FBCache * cache;
    Matrix * x, * y, * z, * gradFBEx;
    double fx, FBEx;

    // test FB operations starting from x1
    x = new Matrix(n, 1, data_x1);
    cache = new FBCache(prob, *x, 1.0);
    fx = cache->get_eval_f();
    y = cache->get_forward_step(gamma1);
    z = cache->get_forward_backward_step(gamma1);
    FBEx = cache->get_eval_FBE(gamma1);
    gradFBEx = cache->get_grad_FBE(gamma1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g1[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g1[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g1, FBEx, DOUBLES_EQUAL_DELTA);

    // change gamma
    y = cache->get_forward_step(gamma2);
    z = cache->get_forward_backward_step(gamma2);
    FBEx = cache->get_eval_FBE(gamma2);
    gradFBEx = cache->get_grad_FBE(gamma2);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g2[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g2[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g2, FBEx, DOUBLES_EQUAL_DELTA);

    delete x;

    delete cache;
}

void TestFBCache::testLogLossPlusL1_small() {
    size_t n = 5;
    size_t m = 5;
    double gamma1 = 0.1;
    double gamma2 = 0.05;
    // starting points
    double data_x1[] = {1, -2, 3, -4, 5};
    // reference results
    double ref_fx1 = 6.513642326541865;
    double ref_y1_g1[] = {1.026894142136999, -1.911920292202212, 3.004742587317756, -3.901798620996209, 5.000669285092428};
    double ref_z1_g1[] = {0.926894142136999, -1.811920292202212, 2.904742587317756, -3.801798620996209, 4.900669285092428};
    double ref_FBEx1_g1 = 21.018928350676088;
    double ref_gradFBEx1_g1[] = {0.716685094584284, -1.861049915114549, 0.948270715102844, -1.978513017309498, 0.992646792853859};
    double ref_y1_g2[] = {1.013447071068500, -1.955960146101106, 3.002371293658878, -3.950899310498105, 5.000334642546214};
    double ref_z1_g2[] = {0.963447071068500, -1.905960146101106, 2.952371293658878, -3.900899310498105, 4.950334642546214};
    double ref_FBEx1_g2 = 21.266285338608977;
    double ref_gradFBEx1_g2[] = {0.723871836607145, -1.870923496546218, 0.950422420962636, -1.980263403673695, 0.992976970964787};

    Function * f = new LogLogisticLoss(1.0);
    Function * g = new Norm1(1.0);
    FBProblem * prob = new FBProblem(*f, *g);

    FBCache * cache;
    Matrix * x, * y, * z, * gradFBEx;
    double fx, FBEx;

    // test FB operations starting from x1
    x = new Matrix(n, 1, data_x1);
    cache = new FBCache(*prob, *x, 1.0);
    fx = cache->get_eval_f();
    y = cache->get_forward_step(gamma1);
    z = cache->get_forward_backward_step(gamma1);
    FBEx = cache->get_eval_FBE(gamma1);
    gradFBEx = cache->get_grad_FBE(gamma1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g1[i], y->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g1[i], z->get(i, 0), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_gradFBEx1_g1[i], gradFBEx->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g1, FBEx, DOUBLES_EQUAL_DELTA);

    // change gamma
    _ASSERT_EQ(FBCache::STATUS_GRAD_FBE, cache->cache_status());
    y = cache->get_forward_step(gamma2);
    _ASSERT_EQ(FBCache::STATUS_FORWARD, cache->cache_status());
    z = cache->get_forward_backward_step(gamma2);
    _ASSERT_EQ(FBCache::STATUS_FORWARDBACKWARD, cache->cache_status());
    FBEx = cache->get_eval_FBE(gamma2);
    _ASSERT_EQ(FBCache::STATUS_FBE, cache->cache_status());
    gradFBEx = cache->get_grad_FBE(gamma2);
    _ASSERT_EQ(FBCache::STATUS_GRAD_FBE, cache->cache_status());

    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_fx1, fx, DOUBLES_EQUAL_DELTA);
    for (int i = 0; i < n; i++) {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_y1_g2[i], y->get(i), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_z1_g2[i], z->get(i), DOUBLES_EQUAL_DELTA);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_gradFBEx1_g2[i], gradFBEx->get(i, 0), DOUBLES_EQUAL_DELTA);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(ref_FBEx1_g2, FBEx, DOUBLES_EQUAL_DELTA);

    delete x;
    delete cache;

    delete prob;
    delete f;
    delete g;
}

void TestFBCache::testNormFPR() {
    const size_t n = 4;
    double data_Q[] = {
        0.38709031607167643, 0.05275627355087711, -0.00567041452897057, -0.04552299262801366,
        0.05275627355087711, 0.41944974781767824, 0.00264334247883102, 0.14679014798515927,
        -0.00567041452897057, 0.00264334247883102, 0.45001600696097127, -0.11712342226158394,
        -0.04552299262801366, 0.14679014798515927, -0.11712342226158394, 0.40344392914967364
    };
    double data_q[] = {
        0.0671663832879185,
        0.3177112577015106,
        0.6169198108394168,
        0.2980171238013654
    };
    double data_x[] = {
        -0.915621290369497,
        -0.519777906036200,
        2.188590138643507,
        -0.518338872582518
    };
    double gamma = 0.04;
    double lambda = 0.3;

    double data_exp_fs[] = {
        -0.903481403431719,
        -0.519021263328163,
        2.121936217451373,
        -0.510256665820712
    };

    double data_exp_fs2[] = {
        -0.891341516493941,
        -0.518264620620125,
        2.055282296259238,
        -0.502174459058907
    };

    double data_exp_fbs[] = {
        -0.891481403431719,
        -0.507021263328163,
        2.109936217451373,
        -0.498256665820712
    };

    double data_exp_FPR[] = {
        -0.0241398869377781,
        -0.0127566427080374,
        0.0786539211921347,
        -0.0200822067618059
    };

    double exp_norm_fpr = 0.0856457846123888;

    Matrix Q(n, n, data_Q);
    Matrix q(n, 1, data_q);
    Matrix x(n, 1, data_x);
    Matrix exp_fs(n, 1, data_exp_fs);
    Matrix exp_fs2(n, 1, data_exp_fs2);
    Matrix exp_fbs(n, 1, data_exp_fbs);
    Matrix exp_FPR(n, 1, data_exp_FPR);

    Function * quadratic = new Quadratic(Q, q);
    Function * norm1 = new Norm1(lambda);

    FBProblem * prob = new FBProblem(*quadratic, *norm1);
    FBCache * cache = new FBCache(*prob, x, gamma);


    double norm_fpr = cache->get_norm_fpr();
    _ASSERT_EQ(FBCache::STATUS_FORWARDBACKWARD, cache->cache_status());
    _ASSERT_NUM_EQ(exp_norm_fpr, norm_fpr, 1e-12);

    int status = cache->update_forward_backward_step(gamma);
    _ASSERT_EQ(ForBESUtils::STATUS_CACHED_ALREADY, status);

    status = cache->update_eval_f(true);
    _ASSERT_EQ(ForBESUtils::STATUS_CACHED_ALREADY, status);

    status = cache->update_forward_backward_step(gamma);
    _ASSERT_EQ(ForBESUtils::STATUS_CACHED_ALREADY, status);

    Matrix * fb = cache->get_forward_step(gamma);
    _ASSERT_EQ(FBCache::STATUS_FORWARDBACKWARD, cache->cache_status());
    _ASSERT_EQ(*fb, exp_fs);

    Matrix * fbs = cache->get_forward_backward_step(gamma);
    _ASSERT_EQ(FBCache::STATUS_FORWARDBACKWARD, cache->cache_status());
    _ASSERT_EQ(*fbs, exp_fbs);

    Matrix * fpr = cache->get_fpr();
    _ASSERT_EQ(*fpr, exp_FPR);

    fb = cache->get_forward_step(2 * gamma);
    _ASSERT_EQ(FBCache::STATUS_FORWARD, cache->cache_status());
    _ASSERT_EQ(*fb, exp_fs2);

    cache->reset();
    _ASSERT_EQ(FBCache::STATUS_NONE, cache->cache_status());

    delete cache;
    delete quadratic;
    delete norm1;
    delete prob;
}

void TestFBCache::testSetDirection() {

    Function * f = new Quadratic();
    Function *g = new Norm1();
    FBProblem * prob = new FBProblem(*f, *g);

    Matrix x(10, 1);
    FBCache * cache = new FBCache(*prob, x, 0.5);

    FBCache * cache2 = new FBCache(*prob, x, 0.5);
    delete cache2;

    Matrix d(10, 1);
    for (size_t i = 0; i < 10; i++) d[i] = i + 1.0;

    cache->set_direction(d);
    Matrix * dir = cache->get_direction();
    d[0] = 10000;

    for (size_t i = 0; i < 10; i++) _ASSERT_NUM_EQ(dir->get(i), i + 1.0, 1e-12);

    delete f;
    delete g;
    delete prob;
    delete cache;

}

void TestFBCache::testXtd() {
    Function * f = new Quadratic();
    Function *g = new Norm1();
    FBProblem * prob = new FBProblem(*f, *g);

    size_t n = 10;
    Matrix x(n, 1);
    for (size_t i = 0; i < n; i++) x[i] = 0.5 * (i + 1.0);

    Matrix d(n, 1);
    for (size_t i = 0; i < n; i++) d[i] = -0.5 * (i + 1.0) / 1.5;
    FBCache * cache = new FBCache(*prob, x, 0.5);

    Matrix x_tau_d(n, 1);
    double tau = 1.5;
    int status = cache->xtd(tau, x_tau_d);
    _ASSERT_EQ(ForBESUtils::STATUS_CACHE_NO_DIRECTION, status);

    cache->set_direction(d);
    status = cache->xtd(tau, x_tau_d);
    _ASSERT_EQ(ForBESUtils::STATUS_OK, status);

    for (size_t i = 0; i < n; i++) _ASSERT_NUM_EQ(0.0, x_tau_d[i], 1e-9);

    for (size_t i = 0; i < n; i++) d[i] = -0.34 * std::sqrt(i + 1.0) + 0.8711;
    cache->set_direction(d);

    double xtd_expected_data[] = {
        0.606220000000000,
        1.078053477758629,
        1.556440545085316,
        2.038220000000000,
        2.522167377530014,
        3.007654697490744,
        3.494308910847608,
        3.981886955517259,
        4.470220000000000,
        4.959185119108550
    };
    Matrix xtd_exp_mat(n, 1, xtd_expected_data);


    tau = 0.20;
    status = cache->xtd(tau, x_tau_d);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_EQ(xtd_exp_mat, x_tau_d);

    delete f, g, prob, cache;

}

void TestFBCache::testF1Extrapolate() {
    size_t n = 5;
    size_t m = 3;
    double Q_data[] = {
        0.4682401168034621, 0.1250290451308249, 0.3947847653912130,
        0.1250290451308249, 0.1889285094926554, 0.0822874869755427,
        0.3947847653912130, 0.0822874869755427, 0.6481945377896851
    };
    Matrix Q(m, m, Q_data);

    double q_data[] = {
        1.252714488082575,
        -0.162112130185000,
        -0.712181636903632
    };
    Matrix q(m, 1, q_data);

    double L1_data[] = {
        -0.692230203627379, 0.431672354643698, 1.863064599390096,
        0.225062443539148, -1.085058314483432, 0.849888831130944,
        -0.409202015705218, -0.169508457312986, -1.374362765552479,
        -0.868945887672006, -0.823226696576784, -0.479066472366443,
        -1.013729375356155, 1.071808719869932, 0.230142693472345
    };
    Matrix L1mat(m, n, L1_data);
    MatrixOperator L1(L1mat);

    double d1_data[] = {
        1.754315938562508,
        0.482182452870281,
        -0.270685669219013
    };
    Matrix d1(m, 1, d1_data);

    double x_data[] = {
        -1.6299024138570919,
        0.0814464520421837,
        -0.8315536121964472,
        -1.5783009661145104,
        -0.2455701367042583
    };
    Matrix x(n, 1, x_data);

    double d_data[] = {
        0.0847805653887511,
        -0.1675336688893896,
        0.0261277258933478,
        -1.0977941989055824,
        -0.0741381776134543
    };
    Matrix d(n, 1, d_data);

    double tau = 1.38222142831014;

    Function *f1 = new Quadratic(Q, q);
    Function *f2 = new HuberLoss(1.0);
    Function *g = new Norm1();

    FBProblem * prob = new FBProblem(*f1, L1, d1, *f2, L1, d1, x, *g);
    FBCache * cache = new FBCache(*prob, x, 0.6);

    int status;
    double fxtd; /* f1(r1(x+tau*d)) */


    cache->set_point(x);

    /* try to invoke f1_extrapolate before a direction is set */
    status = cache->extrapolate_f1(tau, fxtd);
    _ASSERT_EQ(ForBESUtils::STATUS_CACHE_NO_DIRECTION, status);
    _ASSERT(ForBESUtils::is_status_error(status));

    cache->set_direction(d);

    status = cache->extrapolate_f1(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(17.1948186096843, fxtd, 1e-10);
    _ASSERT_EQ(FBCache::STATUS_EVALF, cache->cache_status());

    tau = 0.234;
    status = cache->extrapolate_f1(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(11.7963718624767, fxtd, 1e-10);

    delete f1, g, prob, cache;
}

void TestFBCache::testF1Extrapolate2() {
    size_t n = 4;
    double Q_data[] = {
        13.07782891441034, 4.27452823704610, -1.94688271579899, -12.55222039172310,
        4.27452823704610, 6.38874532934156, -2.56106107234657, -5.16047746739994,
        -1.94688271579899, -2.56106107234657, 12.93139407969478, 4.44426900591413,
        -12.55222039172310, -5.16047746739994, 4.44426900591413, 21.33625765427502
    };
    Matrix Q(n, n, Q_data);

    double q_data[] = {
        0.350344120851833,
        0.287966108884680,
        0.595863756330157,
        0.526051569078466
    };
    Matrix q(n, 1, q_data);

    double x_data[] = {
        -0.844580319722079,
        -0.149690044062781,
        -0.491888830298357,
        -1.821438441093365
    };
    Matrix x(n, 1, x_data);

    double d_data[] = {
        -0.853564753907463,
        0.991480551399332,
        -0.106873218071040,
        0.104843658971077
    };
    Matrix d(n, 1, d_data);

    double tau = 0.2145;

    Function *f = new Quadratic(Q, q);
    Function *g = new Norm1();

    FBProblem * prob = new FBProblem(*f, *g);

    FBCache * cache = new FBCache(*prob, x, 0.5);

    cache->set_direction(d);

    double fxtd;
    int status = cache->extrapolate_f1(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(21.8328487277322, fxtd, 1e-9);

    tau = 0.321045;
    status = cache->extrapolate_f1(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(21.4720009598411, fxtd, 1e-9);

    delete f, g, prob, cache;
}

void TestFBCache::testFExtrapolate() {
    size_t n = 4;
    double Q_data[] = {
        13.07782891441034, 4.27452823704610, -1.94688271579899, -12.55222039172310,
        4.27452823704610, 6.38874532934156, -2.56106107234657, -5.16047746739994,
        -1.94688271579899, -2.56106107234657, 12.93139407969478, 4.44426900591413,
        -12.55222039172310, -5.16047746739994, 4.44426900591413, 21.33625765427502
    };
    Matrix Q(n, n, Q_data);

    double q_data[] = {
        0.350344120851833,
        0.287966108884680,
        0.595863756330157,
        0.526051569078466
    };
    Matrix q(n, 1, q_data);

    double x_data[] = {
        -0.844580319722079,
        -0.149690044062781,
        -0.491888830298357,
        -1.821438441093365
    };
    Matrix x(n, 1, x_data);

    double d_data[] = {
        -0.853564753907463,
        0.991480551399332,
        -0.106873218071040,
        0.104843658971077
    };
    Matrix d(n, 1, d_data);

    double lin_data[] = {
        0.291358532103149,
        0.336135817296440,
        -3.309824834569000,
        2.948510964771869
    };
    Matrix lin(n, 1, lin_data);

    double tau = 0.321045;

    double lambda = 0.158723447167506;
    double mu = 0.224147467167506;

    Function *f1 = new Quadratic(Q, q);
    Function *f2 = new ElasticNet(lambda, mu);

    FBProblem * prob = new FBProblem();
    prob->setF1(f1);
    prob->setF2(f2);
    prob->setLin(&lin);

    FBCache * cache = new FBCache(*prob, x, 0.5);

    cache->set_direction(d);

    double fxtd;
    int status = cache->extrapolate_f(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(18.8574969048016, fxtd, 1e-10);
    _ASSERT_EQ(FBCache::STATUS_EVALF, cache->cache_status());
    _ASSERT(cache->m_betas_fresh);
    _ASSERT(cache->m_lind_fresh);
    _ASSERT(cache->m_L2d_fresh);
    _ASSERT_EQ(cache->m_L2d, cache->m_dir);

    status = cache->extrapolate_f(tau, fxtd);
    _ASSERT_NUM_EQ(18.8574969048016, fxtd, 1e-10);
    _ASSERT_EQ(ForBESUtils::STATUS_CACHED_ALREADY, status);

    status = cache->extrapolate_f(5 * tau, fxtd);
    _ASSERT_NEQ(ForBESUtils::STATUS_CACHED_ALREADY, status);

    delete f1, f2, prob, cache;
}

void TestFBCache::testFExtrapolate2() {
    size_t n = 4;
    size_t m = 2;

    double Q_data[] = {0.0196669491695277, 0.0353499033971591,
        0.0353499033971591, 0.0660050923493463};
    Matrix Q(m, m, Q_data);

    double q_data[] = {0.350344120851833, 0.287966108884680};
    Matrix q(m, 1, q_data);

    double lin_data[] = {0.291358532103149,
        0.336135817296440,
        -3.309824834569000,
        2.948510964771869};
    Matrix lin(n, 1, lin_data);

    double L1_data[] = {0.661645791969063, -0.726522971996173,
        0.177376340590633, -0.742597897889183,
        0.353154498589040, 0.934864940814033,
        -0.895801374284240, -1.139320664614462};
    Matrix L1_mat(m, n, L1_data);
    MatrixOperator L1(L1_mat);


    double L2_data[] = {0.3721975806266081, -0.7303500338761102,
        -0.0804066652790337, -2.1302110677448840,
        0.0910764107884579, 0.0866280025361929,
        -0.6560200562915182, -1.1576835229183660};
    Matrix L2_mat(m, n, L2_data);
    MatrixOperator L2(L2_mat);

    double d2_data[] = {0.5426627116070973, -0.0355871044719014};
    Matrix d2(m, 1, d2_data);

    double x_data[] = {
        -0.844580319722079,
        -0.149690044062781,
        -0.491888830298357,
        -1.821438441093365
    };
    Matrix x(n, 1, x_data);

    double d_data[] = {
        -0.853564753907463,
        0.991480551399332,
        -0.106873218071040,
        0.104843658971077
    };
    Matrix d(n, 1, d_data);

    double tau = 0.459987078261;

    double lambda = 0.158723447167506;
    double mu = 0.224147467167506;

    Function *f1 = new Quadratic(Q, q);
    Function *f2 = new ElasticNet(lambda, mu);

    FBProblem * prob = new FBProblem();
    prob->setLin(&lin);
    prob->setF1(f1);
    prob->setF2(f2);
    prob->setL1(&L1);
    prob->setL2(&L2);
    prob->setD2(&d2);
    prob->setL1(&L1);

    FBCache * cache = new FBCache(*prob, x, 0.5);

    cache->set_direction(d);

    double fxtd;
    int status = cache->extrapolate_f(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_NUM_EQ(-1.37225660471873, fxtd, 1e-10);

    status = cache->extrapolate_f(tau, fxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));
    _ASSERT_EQ(ForBESUtils::STATUS_CACHED_ALREADY, status);

    _ASSERT_NEQ(NULL, cache->m_Qu);

    delete f1, f2, prob, cache;

}

void TestFBCache::testGradfExtrapolate() {
    size_t n = 4;
    size_t m = 2;

    double Q_data[] = {0.0196669491695277, 0.0353499033971591,
        0.0353499033971591, 0.0660050923493463};
    Matrix Q(m, m, Q_data);

    double q_data[] = {0.350344120851833, 0.287966108884680};
    Matrix q(m, 1, q_data);

    double lin_data[] = {0.291358532103149,
        0.336135817296440,
        -3.309824834569000,
        2.948510964771869};
    Matrix lin(n, 1, lin_data);

    double L1_data[] = {0.661645791969063, -0.726522971996173,
        0.177376340590633, -0.742597897889183,
        0.353154498589040, 0.934864940814033,
        -0.895801374284240, -1.139320664614462};
    Matrix L1_mat(m, n, L1_data);
    MatrixOperator L1(L1_mat);


    double L2_data[] = {
        0.03721975806266081, -0.07303500338761101,
        -0.00804066652790337, -0.21302110677448841,
        0.00910764107884579, 0.00866280025361929,
        -0.06560200562915182, -0.11576835229183660
    };
    Matrix L2_mat(m, n, L2_data);
    MatrixOperator L2(L2_mat);

    double d2_data[] = {0.5426627116070973, -0.0355871044719014};
    Matrix d2(m, 1, d2_data);

    double x_data[] = {
        -0.844580319722079,
        -0.149690044062781,
        -0.491888830298357,
        -1.821438441093365
    };
    Matrix x(n, 1, x_data);

    double d_data[] = {
        -0.853564753907463,
        0.991480551399332,
        -0.106873218071040,
        0.104843658971077
    };
    Matrix d(n, 1, d_data);

    double tau = 0.459987078261;

    double delta = 0.600936754424950;

    Function *f1 = new Quadratic(Q, q);
    Function *f2 = new HuberLoss(delta);

    FBProblem * prob = new FBProblem();
    prob->setLin(&lin);
    prob->setF1(f1);
    prob->setF2(f2);
    prob->setL1(&L1);
    prob->setL2(&L2);
    prob->setD2(&d2);
    prob->setL1(&L1);

    FBCache * cache = new FBCache(*prob, x, 0.5);

    cache->set_direction(d);

    Matrix gradfxtd(L1.dimensionIn());
    int status;
    status = cache->extrapolate_gradf(tau, gradfxtd);
    _ASSERT(ForBESUtils::is_status_ok(status));


    double grad_exp_data[] = {
        0.26634801035216965,
        0.00116402299173093,
        -2.71755774709892650,
        1.93411868268163012
    };
    Matrix grad_exp(n, 1, grad_exp_data);
    _ASSERT_EQ(gradfxtd, grad_exp);
    
    delete f1, f2, prob, cache;

}
