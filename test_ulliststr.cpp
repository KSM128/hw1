#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  cout << "is list empty? " << list.empty() << endl;
  cout << "list size is " << list.size() << endl;
  list.push_back("one");
  cout << "First pushback, back: " << list.back() << endl;
  list.push_back("two");
  cout << "Second pushback, back: " << list.back() << endl;
  cout << "Second pushback, front: " << list.front() << endl;
  cout << "Second pushback, size: " << list.size() << endl;

  list.push_front("three");
  list.push_front("four");
  cout << "Pushfront, front: " << list.front() << endl;
  cout << "Pushfront, size: " << list.size() << endl;

  list.pop_back();
  list.pop_front();
  cout << "Pop, front: " << list.front() << endl;
  cout << "Pop, back: " << list.back() << endl;

}
