#ifndef TESTFBCACHE_H
#define	TESTFBCACHE_H

#define FORBES_TEST_UTILS

#include "ForBES.h"
#include "ForBESUtils.h"

#include <cppunit/extensions/HelperMacros.h>

class TestFBCache : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestFBCache);

    CPPUNIT_TEST(testSetDirection);
    CPPUNIT_TEST(testNormFPR);
    CPPUNIT_TEST(testBoxQP_small);
    CPPUNIT_TEST(testSparseLeastSquares_small);
    CPPUNIT_TEST(testSparseLogReg_small);
    CPPUNIT_TEST(testLogLossPlusL1_small);
    
    CPPUNIT_TEST_SUITE_END();

public:
    TestFBCache();
    virtual ~TestFBCache();
    void setUp();
    void tearDown();

private:
    void testSetDirection();
    void testNormFPR();
    void testBoxQP_small();
    void testSparseLeastSquares_small();
    void testSparseLogReg_small();
    void testLogLossPlusL1_small();
};

#endif	/* TESTFBCACHE_H */

