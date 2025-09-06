#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  // remove top k values of stack
  for(int i=0;i<K;i++){
    if(empty()) break;
    pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //remove top k and also return the stack that contain the value that remove in the order of default stack
  std::stack<T> s1,s2;// must write std:: (confused with CP::)
  for(int i=0;i<K;i++){
    if(empty()) break;
    s1.push(top());
    pop();
  }
  int s=s1.size();//use this instead of s1.size() in loop because if use s1.size() the bound will decrease every time
  for(int i=0;i<s;i++){
    s2.push(s1.top());
    s1.pop();
  }
  return s2;
  //don't forget to return an std::stack
}

#endif
