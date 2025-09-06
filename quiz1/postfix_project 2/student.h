#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include<stack>
using namespace std;
//problem:vector v consists of pair of int,int first is 0 if operator and if it is operator second value is 0=+ 1=- 2=* 3=/
//if it first is 1 then second is operand
int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  
  stack<int> s;
  for(auto x:v){
    if(x.first==0){
      int second=s.top();
      s.pop();
      int first=s.top();
      s.pop();
      if(x.second==0){
        int temp1=(first+second);//calculate according to operator and store the result in stack
        s.push(temp1);
      }
      else if(x.second==1){
        int temp2=(first-second);
        s.push(temp2);
      }
      else if(x.second==2){
        int temp3=(first*second);
        s.push(temp3);
      }
      else if(x.second==3){
        int temp4=(first/second);
        s.push(temp4);
      }
    }else{
      s.push(x.second);
    }
  }
  return s.top();// Lastly, the only one value in the stack is the result.
}

#endif
