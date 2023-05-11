#ifndef _ADD_HPP_
#define _ADD_HPP_
#include "base.hpp"
#include <iostream>
using namespace std;

class Add:public Base{
	private:
		double r;
		double l;
		string rstr;
		string lstr;
	public:
		Add(Base* left, Base* right){
			l=left->evaluate();
			r=right->evaluate();
			rstr=left->stringify();
			lstr=right->stringify();
		}
		double evaluate(){return l + r;}
		string stringify(){return"(" + rstr + " + " + lstr + ")";}
};
#endif //_ADD_HPP_