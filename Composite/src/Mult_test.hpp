#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "Mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Op* op1 = new Op(5);
    Op* op2 = new Op(6);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 30);
}

TEST(MultTest, MultStringTwoNums) {
    Op* op1 = new Op(5);
    Op* op2 = new Op(6);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(), "(5 * 6)");
}

TEST(MultTest, MultStringTwoNegativeNums) {
    Op* op1 = new Op(-5);
    Op* op2 = new Op(6);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(), "(-5 * 6)");
}

TEST(MultTest, MultEvaluateTwoNegativeNums) {
    Op* op1 = new Op(-5);
    Op* op2 = new Op(6);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), -30);
}

TEST(MultTest, MultStringTwoZeroes) {
    Op* op1 = new Op(0);
    Op* op2 = new Op(0);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(), "(0 * 0)");
}

TEST(MultTest, MultEvaluateTwoZeroes) {
    Op* op1 = new Op(0);
    Op* op2 = new Op(0);
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateWithMult) {
    Op* op1 = new Op(5);
    Op* op2 = new Op(6);
    Mult* test = new Mult(op1, op2);
    Mult* test2 = new Mult(test, test);
    EXPECT_EQ(test2->evaluate(), 900);
}

TEST(MultTest, MultEvaluateWithNegativeMult) {
    Op* op1 = new Op(5);
    Op* op2 = new Op(6);
    Op* op3 = new Op(-5);
    Op* op4 = new Op(6);
    Mult* test1 = new Mult(op1, op2);
    Mult* test2 = new Mult(op3, op4);

    Mult* test3 = new Mult(test1, test2);
    EXPECT_EQ(test3->evaluate(), -900);
}

TEST(MultTest, MultStringWithNegativeMult) {
    Op* op1 = new Op(5);
    Op* op2 = new Op(6);
    Op* op3 = new Op(-5);
    Op* op4 = new Op(6);
    Mult* test1 = new Mult(op1, op2);
    Mult* test2 = new Mult(op3, op4);

    Mult* test3 = new Mult(test1, test2);
    EXPECT_EQ(test3->stringify(), "((5 * 6) * (-5 * 6))");
}

#endif