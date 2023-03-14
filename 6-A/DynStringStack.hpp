#ifndef DYNSTRINGSTACK_HPP
#define DYNSTRINGSTACK_HPP

#include <string>

class DynStringStack
{
    private: 
        //structure for stack nodes
        struct StackNode
        {
            std::string string;     //string in node
            StackNode *next;        //pointer to next node
        };
        StackNode *top;             //pointer to the stack top
    
    public:
        //default constructor
        DynStringStack()
        { top = nullptr; }

        //destructor
        ~DynStringStack();

        //stack operations
        void push(std::string);
        void pop();
        bool isEmpty();

        //getter for top
        StackNode* getTop() const 
            { return top; }
};

#endif // DYNSTRINGSTACK_HPP