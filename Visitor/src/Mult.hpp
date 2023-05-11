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
	    le = left;
	    ri = right;
	}
        virtual double evaluate() { return l * r;}
	virtual std::string stringify() { return "(" + lstr + " * " + rstr + ")";}
        int number_of_children(){
            int num = 0;
            if(le != NULL){
                num++;
            }
            if(ri != NULL){
                num++;
            }
            return num;
            }
         Base* get_child(int i){
             if(i == 0){
                 return le;
             }
             else if(i == 1){
                 return ri;
             }
	     return nullptr;
         }
	 virtual std::string print(){
	     return "*";
	 }
    void accept(Visitor* visitor, int index){
      if(index == 0){
          visitor->visit_mult_begin(this);
      }
      if(index == 1){
          visitor->visit_mult_middle(this);
      }
      if(index == 2){
          visitor->visit_mult_end(this);
      }
    }
    private:
        double l, r;
        std::string lstr, rstr;	
        Base* le;
	Base* ri;
};

#endif