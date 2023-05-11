#ifndef RAND_HPP
#define RAND_HPP

#include "base.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Rand: public Base {
    public:
        Rand() : Base() {
	    val = rand() % 100;
	    str = std::to_string(val);
	    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	    str.erase(str.find_last_not_of('.') + 1, std::string::npos);
	}
	virtual double evaluate() { return val;}
        virtual std::string stringify() { return str;}
        virtual Base* get_child(int i){return NULL;}
        int number_of_children(){
	    return 0;
	}
	virtual std::string print(){
	    return stringify();
	}
    void accept(Visitor* visitor, int index){
	    visitor->visit_rand(this);
    }
    private:
        double val;
        std::string str;	

};

#endif