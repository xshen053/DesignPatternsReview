#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <stack>
#include <utility>

#include "./src/base.hpp"

class Iterator {
    protected:
        struct base_iterator
        {
            base_iterator(Base* ptr);

            // current node
            Base* ptr;

            // which visit to that node is being made 
            // (0, 1, or 2 for binary operators).
            int index;

            
            int number_children;
        };
        std::stack<base_iterator> node_stack;

    public:
        Iterator(Base* ptr);

        // advances the iterator to the next node to be visited.
        void next();

        // When is_done() returns true, iteration has finished, 
        // and you must not call any other functions on the iterator.
        bool is_done();

        // returns a pointer to the current node being visited
        Base* current_node();

        // tells you which visit to that node is being made 
        // (0, 1, or 2 for binary operators). 
        int current_index();
};

#endif