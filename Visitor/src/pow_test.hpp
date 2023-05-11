#ifndef __POWTEST_HPP__
#define __POWTEST_HPP__


#include "gtest/gtest.h"
#include "pow.hpp"

TEST(PowTest, pos) {
    Op* l = new Op(8);
    Op* r = new Op(2);
    Pow* a=new Pow(l,r);
    EXPECT_EQ(a->evaluate(), 64);
    EXPECT_EQ(a->stringify(),"(8 ** 2)");
}

TEST(PowTest, neg) {
    Op* l = new Op(-8);
    Op* r = new Op(1);
    Pow* a=new Pow(l,r);
    EXPECT_EQ(a->evaluate(), -8);
    EXPECT_EQ(a->stringify(),"(-8 ** 1)");
}

TEST(PowTest, powpow){

    Op* l = new Op(2);
    Op* m = new Op(2);
    Op* s = new Op(2);
    Pow* a = new Pow(l,s);
    Pow* b = new Pow(a,m);
    EXPECT_EQ(b->evaluate(), 16);
    EXPECT_EQ(b->stringify(), "((2 ** 2) ** 2)");
}

TEST(PowTest, Coverage){

    Op* op1 = new Op(3);
    Op* op2 = new Op(4);
    Op* op3 = new Op(2);
    Add* add1 = new Add(op1, op2);
    Add* add2 = new Add(op3, op1);
    Div* div1 = new Div(op2, op3);
    Sub* sub1 = new Sub(add2, div1);
    Pow* pow1 = new Pow(add1, sub1);
    EXPECT_EQ(pow1->evaluate(), 343);
    EXPECT_EQ(pow1->stringify(), "((3 + 4) ** ((2 + 3) - (4 / 2)))");
}

#endif