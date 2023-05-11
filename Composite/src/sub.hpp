#ifndef _SUB_HPP_
#define _SUB_HPP_
#include "base.hpp"
#include <iostream>
using namespace std;

class Sub:public Base{
	private:
		double r;
		double l;
		string rstr;
		string lstr;
	public:
		Sub(Base* left, Base* right){
			l=left->evaluate();
			r=right->evaluate();
			rstr=left->stringify();
			lstr=right->stringify();
		}
		double evaluate(){return l - r;}
		string stringify(){return "("+ rstr + " - " + lstr + ")";}
};


#endif //_SUB_HPP_
