#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 0.8);
}

TEST(DivTest, DivEvaluateWithMult) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(5);
    Mult* mult1 = new Mult(op1, op2);
    Div* test = new Div(mult1, op2);
    EXPECT_EQ(test->evaluate(), 4);
}

TEST(DivTest, DivEvaluateOneDividesZero) {
    Op* op1 = new Op(1);
    Op* op2 = new Op(0);
    Div* test = new Div(op1, op2);
    EXPECT_NE(test->evaluate(), 1);
}

#endif