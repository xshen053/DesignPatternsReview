#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Mult : public Base {
 public:
  Mult(Base* l, Base* r) : Base() {
    
  }
  virtual double evaluate() { return num; }
  virtual std::string stringify() { return str; }
 private:
  double num;
  std::string str;
 
    
};

#endif //__OP_HPP__
