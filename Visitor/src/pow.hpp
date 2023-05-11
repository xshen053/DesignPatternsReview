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
		Base* le;
		Base* ri;
	public:
		Pow(Base* left, Base* right):Base(){
			l=left->evaluate();
			r=right->evaluate();
			lstr=left->stringify();
			rstr=right->stringify();
			le = left;
			ri = right;
		}
		double evaluate(){
			double a=1;
			for(int i=0; i<r; i++){
				a=a*l;
			}
			return a;
		}
		std::string stringify(){return"(" + lstr + " ** " + rstr  + ")";}
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
		    return "**";
		}
        void accept(Visitor* visitor, int index){
      if(index == 0){
                        visitor->visit_pow_begin(this);
                    }
                    if(index == 1){
                        visitor->visit_pow_middle(this);
                        }
                    if(index == 2){
                        visitor->visit_pow_end(this);
                    }
    }


};
#endif //_POW_HPP_