#include "TestSVDHelper.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestSVDHelper);

TestSVDHelper::TestSVDHelper() {
}

TestSVDHelper::~TestSVDHelper() {
}

void TestSVDHelper::setUp() {
}

void TestSVDHelper::tearDown() {
}

void TestSVDHelper::testNs01() {
    double * nullSpace = NULL;
    int p;
    int m = 4;
    int n = 6;
    int info = SVDHelper::nullspace(a_null_2, m, n, nullSpace, p);
    _ASSERT_EQ(SVDHelper::SVD_SUCCESS, info);
    _ASSERT_EQ(2, p);

    double nsExpected[12] = {
        -0.0692563632379673, -0.1964315813960945, 0.5057319556801074,
        0.2359869561185604, 0.7481730291350327, -0.2922339028963962,
        0.5177303465648676, -0.2936094794743029, 0.5990560489350364,
        -0.2257455861733410, -0.1879542979438713, 0.4478757910969019
    };

    for (int i = 0; i < 12; ++i) {
        _ASSERT_NUM_EQ(nsExpected[i], nullSpace[i], 1e-6);
    }
    if (nullSpace != NULL) {
        delete[] nullSpace;
        nullSpace = NULL;
    }
}

void TestSVDHelper::testNs02() {
    double * nullSpace = NULL;
    int p;
    int m = 4;
    int n = 6;
    int info = SVDHelper::nullspace(a_null_3, m, n, nullSpace, p);
    _ASSERT_EQ(SVDHelper::SVD_SUCCESS, info);
    _ASSERT_EQ(3, p);
    double nsExpected[18] = {
        0.64619075422602168, -0.34104962288190338, 0.25476298987281260,
        -0.21132885036954460, 0.15070319728472187, 0.57779507284644727,
        0.00633272318908074, -0.10795982886285169, -0.29264870310563396,
        0.20890717990302557, 0.92080512648390955, -0.10553206984334622,
        0.13385874194894609, 0.14598506805839595, -0.89098658973619038,
        -0.14557147669766590, -0.19643697166833413, 0.32731415391323937
    };

    for (int i = 0; i < 18; ++i) {
        _ASSERT_NUM_EQ(nsExpected[i], nullSpace[i], 1e-6);
    }

    if (nullSpace != NULL) {
        delete[] nullSpace;
        nullSpace = NULL;
    }
}

void TestSVDHelper::testNsEmpty() {
    double * nullSpace = NULL;
    int p;
    int m = 4;
    int n = 4;
    int info = SVDHelper::nullspace(a_square_full, m, n, nullSpace, p);
    _ASSERT_EQ(SVDHelper::SVD_SUCCESS, info);
    _ASSERT_EQ(0, p);
    _ASSERT(NULL == nullSpace);
    if (nullSpace != NULL) {
        delete[] nullSpace;
        nullSpace = NULL;
    }
}

void TestSVDHelper::testNs1B() {
    double * nullSpace = NULL;
    int p;
    int m = 4;
    int n = 4;
    int info = SVDHelper::nullspace(a_square_null_1, m, n, nullSpace, p);
    _ASSERT_EQ(SVDHelper::SVD_SUCCESS, info);
    _ASSERT_EQ(1, p);
    if (nullSpace != NULL) {
        delete[] nullSpace;
        nullSpace = NULL;
    }
}

void TestSVDHelper::testNsTall1() {
    double * nullSpace = NULL;
    int p;
    int m = 5;
    int n = 3;
    int info = SVDHelper::nullspace(a_tall_null_1, m, n, nullSpace, p);
    _ASSERT_EQ(SVDHelper::SVD_SUCCESS, info);
    _ASSERT_EQ(1, p);

    double nsExpected[3] = {0.154303349962092, 0.617213399848368, -0.771516749810459};
    for (int i = 0; i < 3; ++i) {
        _ASSERT_NUM_EQ(nsExpected[i], nullSpace[i], 1e-6);
    }

    if (nullSpace != NULL) {
        delete[] nullSpace;
        nullSpace = NULL;
    }
}

void TestSVDHelper::testSvd1() {
    const int m = 4;
    const int n = 6;
    const int s = MIN(m, n);

    double S[s];
    double U[m * m];
    double V[n * n];

    int info = SVDHelper::dsvd(a_null_2, m, n, S, U, V);
    _ASSERT_EQ(SVDHelper::SVD_SUCCESS, info);
    double S_expected[s] = {
        23.50760646928343,
        16.86167973054917,
        13.63422109487828,
        4.73291143864611
    };

    for (int i = 0; i < s; ++i) {
        double err = fabs(S_expected[i] - S[i]);
        _ASSERT(err < 1e-4);
    }
}
