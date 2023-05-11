#ifndef __MultMock_HPP__
#define __MultMock_HPP__

#include "../base.hpp"

class MultMock : public Base {
 public:
  MultMock(Base* l, Base* r) : Base() {
  }
  virtual double evaluate() { return 5; }
  virtual std::string stringify() { return "5"; }
 private:
  double num;
  std::string str;
 
    
};

#endif //__MultMock_HPP__
