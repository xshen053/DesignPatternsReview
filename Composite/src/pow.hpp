#ifndef _POW_HPP_
#define _POW_HPP_
#include "base.hpp"
#include <iostream>
#include <string>
class Pow:public Base{
	private:
		double l;
		double r;
		std::string lstr;
            	std::string rstr;
		std::string fin;
	public:
		Pow(Base* left, Base* right):Base(){
			l=left->evaluate();
			r=right->evaluate();
			lstr=left->stringify();
			rstr=right->stringify();
		}
		double evaluate(){
			double a=1;
			for(int i=0; i<r; i++){
				a=a*l;
			}
			return a;
		}
		std::string stringify(){return"(" + lstr + " ** " + rstr  + ")";}
};
#endif //_POW_HPP_