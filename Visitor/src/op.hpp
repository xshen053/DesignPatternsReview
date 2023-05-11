#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {
        num = value;
	val = std::to_string(value);
	val.erase(val.find_last_not_of('0') + 1, std::string::npos);
        val.erase(val.find_last_not_of('.') + 1, std::string::npos);

	}
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return val; }
	int number_of_children(){return 0;}
	virtual Base* get_child(int i){return NULL;}
	virtual std::string print(){
	    return stringify();
	}
      void accept(Visitor* visitor, int index){
      visitor->visit_op(this);
    }
    private:
	std::string val;
	double num;
};

#endif //__OP_HPP__