#ifndef __SUBTEST_HPP__
#define __SUBTEST_HPP__

#include "gtest/gtest.h"
#include "sub.hpp"

TEST(SubTest, pos) {
    Op* l = new Op(8);
    Op* r = new Op(2);
    Sub* a=new Sub(l,r);
    EXPECT_EQ(a->evaluate(), 6);
    EXPECT_EQ(a->stringify(),"(8 - 2)");
}

TEST(SubTest, neg) {
    Op* l = new Op(-8);
    Op* r = new Op(2);
    Sub* a=new Sub(l,r);
    EXPECT_EQ(a->evaluate(), -10);
    EXPECT_EQ(a->stringify(),"(-8 - 2)");
}
TEST(SubTest,3numbers){
    Op* l = new Op(8);
    Op* m = new Op(8);
    Op* s = new Op(1);
    Op* n = new Op(1);
    Sub* a = new Sub(l, m);
    Sub* b = new Sub(s, n);
    Sub* c = new Sub(a, b);

    EXPECT_EQ(c->evaluate(), 0);
    EXPECT_EQ(c->stringify(), "((8 - 8) - (1 - 1))");




}


#endif