#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem : operator overload (>=) of CP:pair
//solution: compare first and compare second if first equal
template <typename T1,typename T2>
bool CP::pair<T1,T2>::operator>=(const pair<T1,T2>& other) const {
  //write your code here
  if(first>other.first){
    return true;
  }
  else if(first==other.first){
    if(second>=other.second) return true;
  }
  return false;
  
}

#endif
