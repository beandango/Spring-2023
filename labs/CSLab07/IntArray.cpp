#include "IntArray.h"
#include <iostream>
using namespace std;

namespace ComputerScience
{
    void IntArray::addNodes(int num)
    {
        //add num nodes (placeholder) to the end of the list

        if(num < 0) return;

        ListNode *newNode;
        //add num nodes to the end of the list
        for(int i=0; i<num; i++){
            //create new node, leave value unassigned bc it is a placeholder
            newNode = new ListNode;
            newNode->next = nullptr;
            newNode->previous = nullptr;

            //add to list
            if(last == nullptr)
            {
                //empty list
                first = last = newNode;
            }
            else
            {
                last->next = newNode; //make current last node point to newNode
                newNode->previous = last; //make newnodepoint back to current last node
                last = newNode; //make newNode become the last node
            }
        }
        length += num; //increase length of arr
        //variables current and currentIndex are not impacted by adding nodes
        //but need to check if currentindex is -1
        if(currentIndex < 0 && length > 0) 
        {
            //make it point to first node
            currentIndex = 0;
            current = first;
        }
    } 


    void IntArray::removeNodes(int num)
    {
        //remove num nodes from the end of the list
        if(num < 0) return;

        //remove num nodes from the end of list
        if(num>length)
            num = length; //num must be <= length
        
        ListNode *tmp;
        for(int i = 0; i < num; i++){
            if(last->previous == nullptr)
            {
                //only one node remaining in the list
                delete last;
                first = last = nullptr;
            }else{
                tmp = last; //remember the last node

                //make next to last be the last
                last = last->previous; //moving back one node
                last->next = nullptr;

                delete tmp; //free the space
            }
        }
        length -= num; //decrease the length of the array

        if(currentIndex > length - 1){
            //the node that variable current points to is removed
            //make the variable current points to the last node
            current = last; //current could be nullptr is list is empty
            currentIndex = length - 1; //currentIndex could be -1 if list is empty
        }
    } 

    //constructor
    IntArray::IntArray(int size)
    {
        //init
        length = 0;
        first = last = current = nullptr;
        currentIndex = -1;

        if (size < 0)
        {
            std::cout << "size of the array must be greater than 0";
        }
        
        else if (size == 0)
        {
            //do nothing
        }
        else
        {
            addNodes(size); //add placeholders
            //make current pointing to first node
            currentIndex = 0;
            current = first;
        }
    }
        
    IntArray::~IntArray()
    {
        //myArray always holds a memory, so safe to free
        removeNodes(length);
    }

    IntArray::IntArray(const IntArray &r){
        //init
        length = 0;
        first = last = current = nullptr;
        currentIndex = -1;

        //copy constructor to init the instance from existing instance
        copyContent(r);
    }

    IntArray& IntArray::operator=(const IntArray& r){
        if(this == &r){ //this is the pointer to itself
            //the address of itself is the same as the address of obj a
            //it is doing a=a. so do nothing
            return *this; //return this object
        }
        //now the right side IntArray r is not the saem obj
        removeNodes(length); //clean current array
        copyContent(r); //copy all
        return *this; //return the ref of the obj
    }

    void IntArray::copyContent(const IntArray& r){
        //copy the content from another obj
        //handle array
        if(r.length == 0){
            //r is empty array
        }else{
            //only allocate mem and copy array when r.length is not 0
            if(r.length > length) {
                //add placeholders
                addNodes(r.length - length);
            }else if (r.length < length){
                //remove extra nodes
                removeNodes(length-r.length);
            }

            //copy contents
            ListNode *n1 = first;
            ListNode *n2 = r.first;
            for(int i = 0; i < length; i++){
                n1->value = n2->value;
                n1 = n1->next;
                n2 = n2->next;
            }
            //make current node point to first node
            currentIndex = 0;
            current = first;
        }
    }

    int IntArray::size() const{
        //getter function to return size of array
        return length;
    }

    //subscript overloading
    int& IntArray::operator[](int i){
        //suscript overloading, return the ref of ith elem
        if(i < 0 || i >= length){
            //out of range
            std::cout<<"the index is out of range";
        }else{
            //make variable current point to the ith node
            //it is highly possible that users move forward so we check if i == currentIndex + 1 first
            if(i == currentIndex + 1){
                current = current->next;
                currentIndex++;
            }else if(i==currentIndex-1){
                current = current->previous;
                currentIndex--;
            }else{
                if(abs(i-0) < abs(i-currentIndex)){
                    //first node closer to i than current node
                    current = first;
                    currentIndex = 0;
                }else if(abs(i-length+1)<abs(i-currentIndex)){
                    //last node is closer
                    current = last;
                    currentIndex = length-1;
                }
                //move to
                if(i>=currentIndex){
                    //move forward
                    while(currentIndex != i){
                        currentIndex++;
                        current = current->next;
                    }
                }else{
                    //move backward
                    while(currentIndex != i){
                        currentIndex--;
                        current = current->previous;
                    }
                }
            }
        }
        return current->value;
    }

    //overloading operator+ to merge two intarrays
    IntArray IntArray::operator+(const IntArray& r) const{
        //create an instance
        IntArray merged(length + r.length);

        //copy content from this obj first
        ListNode *p1 = merged.first;
        ListNode *p2 = first;

        //copy content from r
        p2 = r.first;
        for(int i=0; i<r.length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        return merged;
    }

    IntArray IntArray::operator+(int val) const{
        //overloading operator + to merge intarrays and an int
        IntArray merged (length + 1); //create an array one element more than this array

        //copy content from this obj first
        ListNode *p1 = merged.first;
        ListNode *p2 = first;
        for(int i=0; i<length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        //put val to the last element
        p1->value = val; 
        return merged; 
    }

    //overloading operator += to append r to this array
    IntArray& IntArray::operator+=(const IntArray& r) {
        
        if (r.length == 0) {
            //appended array is empty. return the reference of this object directly 
            return *this;
        }
        //following code works for both a += a; and a += b; 
        //create a new combined array to hold merged arrays
        ListNode *p1 = last;
        //record r.length since it will be changed after addNodes if doing a += a
        int rLength = r.length;

        addNodes(r.length); //pointer last and membver length of this obj is changed within addNodes()

        //copying value
        p1 = p1->next;
        ListNode *p2 = r.first;
        for(int i=0; i<rLength; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        return *this; 
    }

    IntArray& IntArray::operator+= (int val) {
        //overloading operator += to append an int to this array 
        addNodes(1);
        last->value = val;
        return *this; 
    }

    void IntArray::Resize(int newSize)
    {
        //resize the array to the length of newSize, Irt preserves the existing values
        if(newSize <= 0){
            std::cout<<"array size must be a positive number";
        }

        if(newSize > length){
            addNodes(newSize-length);
        }
        else{
            removeNodes(length-newSize);
        }
    }

    IntArray operator+(int val, const IntArray& r){
        //commutative + of IntArray operator+(int)
        IntArray merged(r.length + 1); //create an array one element more than this array

        //put val to the first node
        IntArray::ListNode *p1 = merged.first;
        p1->value = val;
        p1 = p1->next;
        IntArray::ListNode *p2 = r.first;
        //copy content from this obj
        for(int i=0; i<r.length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        return merged;
    }

    std::ostream& operator<< (std::ostream & out, const IntArray& r){
        IntArray::ListNode *p = r.first;
        for(int i=0; i<r.length; i++){
            out<<p->value<<' ';
            p = p->next;
        }
        return out;
    }

    std::istream& operator>> (std::istream & in, IntArray& r){
        IntArray::ListNode *p = r.first;
        for(int i=0; i<r.length;i++)
        {
            in >> p->value;
            p = p->next;
        }
        return in;
    }

}