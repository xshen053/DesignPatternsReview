#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

class Div: public Base {
    public:
	Div(): Base(){}    
        Div(Base* left, Base* right): Base() {
            l = left->evaluate();
            r = right->evaluate();
            lstr = left->stringify();
            rstr = right->stringify();
            le = left;
	    ri = right;
        }
        virtual double evaluate() { return l / r;}
        virtual std::string stringify() { return "(" + lstr + " / " + rstr + ")";}
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
	    return "/";
	}	
      void accept(Visitor* visitor, int index){
      	    if(index == 0){
	        visitor->visit_div_begin(this);
	    }
	    if(index == 1){
	        visitor->visit_div_middle(this);
	    }
	    if(index == 2){
	        visitor->visit_div_end(this);
	    }
    }
    private:
        double l, r;
        std::string lstr, rstr;
	Base* le;
	Base* ri;

};

#endif