#include "DynStringStack.hpp"
#include <iostream>

//destructor
DynStringStack::~DynStringStack()
{
    StackNode *nodePtr = nullptr, *nextNode = nodePtr;

    //position nodePtr at the top of the stack
    nodePtr = top;

    //traverse the list deleting each node
    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//stack operations
void DynStringStack::push(std::string str)
{
    StackNode *newNode = nullptr;       //pointer to new node

    //allocate a new node and store string there
    newNode = new StackNode;
    newNode->string = str;

    //if no nodes in list
    //make newNode the first
    if(isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else       //otherwise, insert newNode before top
    {
        newNode->next = top;
        top = newNode;
    }
}
void DynStringStack::pop()
{
    if(isEmpty())
    {
        return;
    }
    else        //pop off top of stack
    {
        StackNode *temp = top;
        top = top->next;
        delete temp;
    }
}
bool DynStringStack::isEmpty()
{
    bool status;

    if(!top)
        status = true;
    else    
        status = false;
    return status;
}