#ifndef __ADDTEST_HPP__
#define __ADDTEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
using namespace std;
TEST(Addtest, Evaluateadd){
	Op* left=new Op(7);
	Op* right=new Op(8);
	Add* test=new Add(left,right);
	EXPECT_EQ(test->evaluate(),15);
	EXPECT_EQ(test->stringify(),"(7 + 8)");
}
TEST(Addtest, 4add){
	Op* l = new Op(5);
	Op* m = new Op(5);
	Op* s = new Op(5);
	Op* n = new Op(5);
	Add* a = new Add(l, m);
	Add* b = new Add(s, n);
	Add* c = new Add(a, b);
EXPECT_EQ(c->evaluate(), 20);
EXPECT_EQ(c->stringify(), "((5 + 5) + (5 + 5))");




}


#endif