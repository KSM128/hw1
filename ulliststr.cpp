#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){ // O(1)
  if(tail_ == NULL || tail_->last >= ARRSIZE){ // when list is empty or list overflows
    Item* newNode = new Item();
    newNode->prev = tail_; // link to previous node
    if(tail_ != NULL){ 
      tail_->next = newNode; // link previous to this
    } else {
      head_ = newNode; // when list is empty ...
    }
    tail_ = newNode; 
  }

  // set value
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  tail_->last--; // move 'last' backward to pop
  size_--;

  if(tail_->first == tail_->last){ // check if list is empty->delete it
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_){
      tail_->next = NULL;
    } else {
      head_ = NULL;
    }
    delete temp;
  } 
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL || head_->first == 0){ // when list empty or overflows
    Item* newNode = new Item();
    newNode->next = head_; // link this to previous
    newNode->first = ARRSIZE;
    newNode->last = ARRSIZE;
    if(head_ != NULL){
      head_->prev = newNode; // link previous to this
    } else {
      tail_ = newNode; // when empty
    }
    head_ = newNode;
  }
  
  // set value
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  head_->first++; // move 'first' forward
  size_--;

  if(head_->first == head_->last){ // check if list is empty->delete it
    Item* temp = head_;
    head_ = head_->next;
    if(head_){
      head_->prev = NULL;
    } else {
      tail_ = NULL;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const { 
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const { // O(1)
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const { // O(n)
  if(loc >= size_){
    return NULL; // return null when non-existent loc provided
  }

  Item* current = head_;
  size_t count = 0;
  while(current != NULL){
    size_t listSize = current->last - current->first; // count the size of a single node
  
    if(loc < count + listSize){ // location found
      return &current->val[current->first + (loc - count)];
    }

    count += listSize;
    current = current->next; // location not found, proceed to next node
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
