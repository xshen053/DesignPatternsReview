#include <iostream>
#include <vector>

#include "iterator.hpp"
#include "visitor.hpp"
#include "./src/add.hpp"
#include "./src/op.hpp"
#include "./src/pow.hpp"
#include "./src/PrintLaTeX.hpp"
#include "./src/Mult.hpp"
#include "./src/div.hpp"
#include "./src/base.hpp"
#include "./src/Math.hpp"

int main()
{
     
    VisitMathML* mathML = new VisitMathML();
    VisitorLatex* latex = new VisitorLatex();

    Base* num0 = new Op(0);
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* num3 = new Op(3);
    Base* num5 = new Op(5);
    Base* a = new Sub(num5, num0);
    
    Base* example1 = new Add(num1, a);
    Base* example2 = new Pow(num5, num2);
    Base* example3 = new Mult(num2, num5);
    Base* example4 = new Div(num2, num3);
    Base* example5 = new Div(example3, example2);


    std::cout << "Visitor Method Parsing\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "\nExample 1: 1+(5-0) \n";
    std::cout << latex->PrintLaTex(example1) << "\n";
    std::cout << mathML->PrintMathML(example1);

    std::cout << "\nExample 2: 5^2 \n";
    std::cout << latex->PrintLaTex(example2) << "\n";
    std::cout << mathML->PrintMathML(example2);
    
    std::cout << "\nExample 3: 2*5 \n";
    std::cout << latex->PrintLaTex(example3) << "\n";
    std::cout << mathML->PrintMathML(example3);
    
    std::cout << "\nExample 4: 2/3 \n";
    std::cout << latex->PrintLaTex(example4) << "\n";
    std::cout << mathML->PrintMathML(example4);
    
    std::cout << "\nExample 5: (2*5) / (5^2) \n";
    std::cout << latex->PrintLaTex(example5) << "\n";
    std::cout << mathML->PrintMathML(example5);

    
    delete example1; delete example2; delete example3; delete example4; delete example5; 
    delete a; delete num0; delete num1; delete num2;  delete num5;
     delete latex;
     delete mathML;
}