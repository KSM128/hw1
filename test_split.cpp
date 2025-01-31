/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

int main(int argc, char* argv[])
{
  Node* list = NULL;
  Node* tail = NULL;

  // generate a new list
  for(int i = 1; i < 13; i+=2){
    Node* newNode = new Node(i, NULL);
    if(!list){
      list = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  Node* odds = NULL;
  Node* evens = NULL;
  // do recursion
  split(list, odds, evens);

  // output results
  std::cout << "Odds: ";
  while(odds){
    std::cout << odds->value << ", ";
    odds = odds->next;
  }

  std::cout << std::endl << "Evens: ";
  while(evens){
    std::cout << evens->value << ", ";
    evens = evens->next;
  }

  // delete memory allocated
  Node* current = odds;
  while(current){
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  odds = nullptr;

  current = evens;
  while(current){
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  evens = nullptr;

  current = list;
  while(current){
    Node* temp = current;
    current = current ->next;
    delete temp;
  }
  list = nullptr;
  // something wrong with memory leak but I really can't see why.

  return 0;
}
