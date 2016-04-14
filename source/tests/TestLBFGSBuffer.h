/*
 * File:   TestLBFGSBuffer.h
 * Author: Pantelis Sopasakis
 *
 */

#ifndef TESTLBFGSBuffer_H
#define	TESTLBFGSBuffer_H

#define FORBES_TEST_UTILS

#include "ForBES.h"

#include <cppunit/extensions/HelperMacros.h>

class TestLBFGSBuffer : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestLBFGSBuffer);

    CPPUNIT_TEST(testPush1);
    CPPUNIT_TEST(testPush2);
    CPPUNIT_TEST(testTwoLoopQuadratic);

    CPPUNIT_TEST_SUITE_END();

public:
    TestLBFGSBuffer();
    virtual ~TestLBFGSBuffer();
    void setUp();
    void tearDown();

private:
    void testPush1();
    void testPush2();
    void testTwoLoopQuadratic();
};

#endif	/* TESTLBFGSBuffer_H */

