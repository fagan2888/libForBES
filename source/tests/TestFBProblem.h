/*
 * File:   TestFBProblem.h
 * Author: Pantelis Sopasakis
 *
 * Created on Apr 17, 2016, 12:25:58 PM
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

#ifndef TESTFBPROBLEM_H
#define TESTFBPROBLEM_H

#define FORBES_TEST_UTILS
#include "ForBES.h"

#include <cppunit/extensions/HelperMacros.h>

class TestFBProblem : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestFBProblem);

    CPPUNIT_TEST(testConstruct);

    CPPUNIT_TEST_SUITE_END();

public:
    TestFBProblem();
    virtual ~TestFBProblem();
    void setUp();
    void tearDown();

private:
    void testConstruct();
};

#endif /* TESTFBPROBLEM_H */

