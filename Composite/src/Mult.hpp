#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

class Mult: public Base {
    public:
        Mult(Base* left, Base* right): Base() {
	    l = left->evaluate();
	    r = right->evaluate();
            lstr = left->stringify();
	    rstr = right->stringify();
	}
        virtual double evaluate() { return l * r;}
	virtual std::string stringify() { return "(" + lstr + " * " + rstr + ")";}
    private:
        double l, r;
        std::string lstr, rstr;	

};

#endif