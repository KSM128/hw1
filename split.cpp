/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  // base case: if no more input stop recursing
  if(in == NULL){
    return;
  }

  // recursive case: first take the node out of original list
  Node* inNode = in;
  in = in->next;
  inNode->next = nullptr;
  
  // use head recursion, otherwise the new lists will be backwards
  split(in, odds, evens);
  // then judge which list this new node belongs to
  if(inNode->value % 2 == 0){
    inNode->next = evens;
    evens = inNode;
  } else {
    inNode->next = odds;
    odds = inNode;
  }
  // split(in, odds, evens);
  
}

/* If you needed a helper function, write it here */
