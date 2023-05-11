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
		Base* le;
		Base* ri;
	public:
		Sub(Base* left, Base* right){
			l=left->evaluate();
			r=right->evaluate();
			rstr=left->stringify();
			lstr=right->stringify();
			le = left;
			ri = right;
		}
		double evaluate(){return l - r;}
		string stringify(){return "("+ rstr + " - " + lstr + ")";}
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
		    return "-";
		}
        void accept(Visitor* visitor, int index){
          if(index == 0){
              visitor->visit_sub_begin(this);
          }
          if(index == 1){
              visitor->visit_sub_middle(this);
              }
          if(index == 2){
              visitor->visit_sub_end(this);
          }
    }

};


#endif //_SUB_HPP_
