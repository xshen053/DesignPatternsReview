#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateDecimal) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8");
}

TEST(OpTest, OpStringZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0");
}

TEST(OpTest, OpStringDecimal) {
    Op* test = new Op(3.4);
    EXPECT_EQ(test->stringify(), "3.4");
}

TEST(OpTest, OpStringDecimalStartZero) {
    Op* test = new Op(0.4);
    EXPECT_EQ(test->stringify(), "0.4");
}

#endif //__OP_TEST_HPP__
