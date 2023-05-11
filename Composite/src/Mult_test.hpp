#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "Mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Op* eight = new Op(8);
    Op* seven = new Op(7);
    Mult* result = new Mult(eight, seven);
    EXPECT_EQ(result->evaluate(), 56);
}

TEST(MultTest, MultEvaluateNonZero) {
    Op* eight = new Op(8);
    Op* seven = new Op(7);
    Mult* temp = new Mult(eight, seven);
    Op* four = new Op(4);
    Mult* result = new Mult(four, temp);
    EXPECT_EQ(result->evaluate(), 224);
}
