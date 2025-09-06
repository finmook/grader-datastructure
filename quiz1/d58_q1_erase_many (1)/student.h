#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem:erase many position at once
//solution: erase backward
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  for(int i=pos.size()-1;i>=0;i--){
    erase(begin()+pos[i]);
  }
}

#endif
