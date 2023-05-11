#ifndef __PRINTLATEX_HPP__
#define __PRINTLATEX_HPP__

#include "../visitor.hpp"
#include "../iterator.hpp"
#include "base.hpp"
#include <iostream>
#include <string>
#include "Rand.hpp"
#include "add.hpp"
#include "div.hpp"
#include "Mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "sub.hpp"
using namespace std;

class VisitorLatex: public Visitor{
    private:
	string result;
    public:

	string PrintLaTex(Base* ptr){
	    result = "";
	    result = result + "$";
	    Iterator iter = Iterator(ptr);
	    while(!iter.is_done()){
	        iter.current_node()->accept(this, iter.current_index());
		iter.next();
	    
	    }
	    result = result + "$";
	    return result;
	}

        virtual void visit_op(Op* node){
	    result = result + "{" + node->stringify() + "}";
	}

         virtual void visit_rand(Rand* node){
            result = result + "{" + node->stringify() + "}";
	}

        virtual void visit_add_begin(Add* node){
	    result = result + "{(";
	}
        virtual void visit_add_middle(Add* node){
	    result = result + "+";
	}
        virtual void visit_add_end(Add* node){
            result = result + ")}";
	}
        virtual void visit_sub_begin(Sub* node){
            result = result + "{(";	
	}
        virtual void visit_sub_middle(Sub* node){
            result = result + "-";	
	}
        virtual void visit_sub_end(Sub* node){
            result = result + ")}";	
	}
        virtual void visit_mult_begin(Mult* node){
            result = result + "{(";	
	}
        virtual void visit_mult_middle(Mult* node){
            result = result + "\\cdot";	
	}
        virtual void visit_mult_end(Mult* node){
	    result = result + ")}";
	}
        virtual void visit_div_begin(Div* node){
	    result = result + "{\\frac";
	}
        virtual void visit_div_middle(Div* node){
            result = result + "";	
	}
        virtual void visit_div_end(Div* node){
	    result = result + "}";
	}
        virtual void visit_pow_begin(Pow* node){
            result = result + "{(";
        }
        virtual void visit_pow_middle(Pow* node){
	    result = result + "^";
	}
        virtual void visit_pow_end(Pow* node){	
            result = result + ")}";
        }



};





#endif