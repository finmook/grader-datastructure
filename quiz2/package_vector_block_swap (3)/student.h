#ifndef __STUDENT_H_
#define __STUDENT_H_
//problem: swap data of two block in vector
//solution: loop through each block and swap data
template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(m==0) return false;
  if(a<begin()||a>=end()|| b<begin()||b>=end()) return false;//testcase let me check this
  if(((a-begin()+m-1)>=mSize)||(((b-begin())+m-1)>=mSize)) return false;//check if out of range
  iterator f;//the smaller iterator
  iterator s;//the larger iterator
  if(a<b){
    f=a;
    s=b;
    if(((a-begin())+m-1)>=(b-begin())) return false;//check if overlap
  }
  else{
    f=b;
    s=a;
    if(((b-begin())+m-1)>=(a-begin())) return false;//check if overlap
  }
  
  for(int i=0;i<m;i++){
    T temp=*(f+i);
    *(f+i)=*(s+i);
    *(s+i)=temp;
  }
  return true;

}

#endif
