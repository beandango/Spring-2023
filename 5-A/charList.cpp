/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 5 A
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 03.06.2023

*/
// Implementation file for the NumberList class

// Your coding required here 
#include "CharList.hpp"
#include <iostream>


//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

void CharList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}


// More of your coding required here 
void CharList::appendNode(char letter)
{
   ListNode *newNode;            // to point to a new node
   ListNode *nodePtr;            // to move through the list

   // Allocate new node and store char there
   newNode = new ListNode;
   newNode->value = letter;
   newNode->next = nullptr;


   // if there are no nodes,
   //make newNode the first node
   if(!head)
      head = newNode;
   else // else, insert newNode at end
   {
      // init nodePtr to head of list
      nodePtr = head;

      // find last node in list
      while(nodePtr->next)
         nodePtr = nodePtr->next;
      
      // insert newNode as the last node
      nodePtr->next = newNode;
   }
}


void CharList::insertNode(char letter)
{
   ListNode *newNode;                  // a new node
   ListNode *nodePtr;                  // to traverse the list
   ListNode *previousNode = nullptr;   // the previous node

   // allocate new node and store letter there
   newNode = new ListNode;
   newNode->value = letter;

   //if there are no nodes in the list
   //make newNode the first
   if(!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else // otherwise, insert new node
   {
      //position nodeptr at the head of list
      nodePtr = head;

      //init prev to nullptr
      previousNode = nullptr;

      //skip all nodes whose value is less than letter
      while(nodePtr!=nullptr && nodePtr->value < letter)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      //if new node is to be the 1st in the list,
      //insert it before all other nodes
      if(previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else //otherwise, insert after the previous node 
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}


void CharList::deleteNode(char letter)
{
   ListNode *nodePtr;            // to traverse the list
   ListNode *previousNode;       // to point to previous node

   // if list is empty, do nothing
   if(!head)
      return;
   
   //determine if the first node is the one to delete
   if(head->value == letter)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }else{
      //init nodePtr to head of list
      nodePtr = head;

      //skip all nodes whose value is 
      //not equal to letter
      while(nodePtr != nullptr && nodePtr->value != letter)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      //if nodeptr is not at the end of the list,
      //link the previousnode to the node after 
      //nodeptr, then delete nodeptr
      if(nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************
CharList::~CharList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
