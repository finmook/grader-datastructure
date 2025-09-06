#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>
//don't forget to detect empty case
template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  //write your code here
  return v[v.size()-1]; //v.back() can be used

}

template <typename T>
void CP::stack<T>::push(const T& element) {
  //write your code here
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  //write your code here
  if(!v.empty()) v.pop_back();
}

#endif
