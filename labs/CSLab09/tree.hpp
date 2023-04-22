/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 8 A
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 04.21.2023
   Purpose. The purpose of this assignment is to make sure that you know how to write a program that
uses containers, algorithms, iterators or binary trees

*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth() const {
      return determineDepth(rootPtr);
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(NODETYPE val) const {
      return binarySearchHelper(rootPtr, val);
   }

   // get the count of nodes in the tree
   int Count() const {
      return countNodes(rootPtr);
   }

   // optimize the binary search tree
   void Optimize() {
      int nodeCount = Count();
      NODETYPE *valuesArray = new NODETYPE[nodeCount];
      int index = 0;

      // Fill the array with in-order traversal
      inOrderToArray(rootPtr, valuesArray, index);

      // Clear the tree
      clearTree(rootPtr);
      rootPtr = nullptr;

      // Re-insert values from the array
      arrayToTree(valuesArray, 0, nodeCount - 1);

      // Free the memory of the allocated array
      delete[] valuesArray;
   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   //rootPtr: the pointer to the root of the tree or sub tree when called recursively
   //         passed from calling statement
   //postcondition: the value returned is the height of the tree (i.e. max depth of the tree)
   //               -1: empty tree (i.e. rootPtr is null)
   //                0: only one node in a whole tree
   //            other: the height is always one less of the number of nodes of the deepest path.
   int determineDepth(TreeNode<NODETYPE> * rootPtr) const {
      if (rootPtr == nullptr) {
         return -1; // Empty tree
      }
      
      int leftDepth = determineDepth(rootPtr->leftPtr);
      int rightDepth = determineDepth(rootPtr->rightPtr);
      
      return 1 + std::max(leftDepth, rightDepth);
   }

   // do a binary search on the Tree, searching the value val within a tree of rootPtr
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE> *rootPtr, NODETYPE val) const{
if (rootPtr == nullptr) {
         return nullptr; // Not found
      }
      
      if (rootPtr->data == val) {
         std::cout << "Comparing " << val << " to " << rootPtr->data << "; search complete" << std::endl;
         return rootPtr; // Found
      }
      
      if (val < rootPtr->data) {
         std::cout << "Comparing " << val << " to " << rootPtr->data << "; smaller, walk left" << std::endl;
         return binarySearchHelper(rootPtr->leftPtr, val); // Walk left
      } else {
         std::cout << "Comparing " << val << " to " << rootPtr->data << "; larger, walk right" << std::endl;
         return binarySearchHelper(rootPtr->rightPtr, val); // Walk right
      }
   }

   //helper functions for int Count and void Optimize
   int countNodes(TreeNode<NODETYPE> *node) const {
      if (node == nullptr) {
         return 0;
      }
      return 1 + countNodes(node->leftPtr) + countNodes(node->rightPtr);
   }

   void inOrderToArray(TreeNode<NODETYPE> *node, NODETYPE *array, int &index) const {
      if (node != nullptr) {
         inOrderToArray(node->leftPtr, array, index);
         array[index++] = node->data;
         inOrderToArray(node->rightPtr, array, index);
      }
   }

   void clearTree(TreeNode<NODETYPE> *node) {
      if (node != nullptr) {
         clearTree(node->leftPtr);
         clearTree(node->rightPtr);
         delete node;
      }
   }

   void arrayToTree(NODETYPE *array, int start, int end) {
      if (start <= end) {
         int mid = (start + end) / 2;
         insertNode(array[mid]);
         arrayToTree(array, start, mid - 1);
         arrayToTree(array, mid + 1, end);
      }
   }

};

#endif // TREE_HPP
