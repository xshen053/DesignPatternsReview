#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "Rand.hpp"


TEST(RandTest, RandEvaluateLT100) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
}

TEST(RandTest, RandStringNE100) {
    Rand* test = new Rand();
    EXPECT_NE(test->stringify(), "100");
}

TEST(RandTest, RandEvaluateEightyThree) {
    Rand* test = new Rand();
    EXPECT_NE(test->evaluate(), 84);
}

TEST(RandTest, RandEvaluateGTNegativeOne) {
    Rand* test = new Rand();
    EXPECT_NE(test->evaluate(), -1);
}




#endif