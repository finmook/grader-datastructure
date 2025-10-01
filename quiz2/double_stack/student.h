#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include<vector>
template <typename T>
//problem: do following function of CP:stack
//solution: separate data stack_a contain data of top half of stack(top value is top value of all data)
// stack_b contain bottom half of stack(top value is the bottom of stack)
// must use this method because if we use temp stack it will false in bottom function because the return of that function is const &
//store data like this is fast
// we have to balance data using balanceStack function

void balanceStack(std::stack<T> &stack_a, std::stack<T> &stack_b, int isPop, bool popBottom)
{
	std::vector<T> allData(stack_a.size() + stack_b.size());//contain all data the first element is the bottom of all data so last element is top of all data
	int sb = stack_b.size();
	int sa = stack_a.size();
	for (int i = 0; i < sb; i++)
	{
		if (!stack_b.empty())
		{
			allData[i] = stack_b.top();//store bottom half data
			stack_b.pop();
		}
	}
	int idx = allData.size() - 1;
	for (int i = 0; i < sa; i++)
	{
		if (!stack_a.empty())
		{
			allData[idx--] = stack_a.top();// store top half data
			stack_a.pop();
		}
	}
	int start = 0;
	int end = allData.size() - 1;
	if(start>end) return;// if it pop all return so both stack a and b is empty()
	if (popBottom)
	{
		start += isPop;//to pop data for pop bottom
	}
	else
		end -= isPop;//to pop data for normal pop
	int partition = (start + end + 1) / 2;//must +1 to make it balance
	for (int i = partition - 1; i >= start; i--)
	{
		stack_b.push(allData[i]);
	}
	for (int i = partition; i <= end; i++)
	{
		stack_a.push(allData[i]);
	}
}
template <typename T>
void CP::stack<T>::pop()
{
	// modify method here
	if (stack_a.empty())
	{
		balanceStack(stack_a, stack_b, 1, false);//pop data using 1 as argument no need to pop() again
	}
	else
	{
		stack_a.pop();
		if (stack_a.empty())
		{
			balanceStack(stack_a, stack_b, 0, false);// if(stack_a empty() so we must call balanceStack again)
		}
	}
}

template <typename T>
const T &CP::stack<T>::top()
{
	// modify method here
	if (stack_a.empty())
		balanceStack(stack_a, stack_b, 0, false);
	return stack_a.top();
}

template <typename T>
const T &CP::stack<T>::bottom()
{
	// write your code here
	// std::stack<T> stack_c=stack_a;
	// std::stack<T> stack_d;
	// while(!stack_c.empty()){
	// 	stack_d.push(stack_c.top());
	// 	stack_c.pop();
	// }
	// return stack_d.top();
	if (stack_b.empty()){
		balanceStack(stack_a, stack_b, 0, false);
		if(stack_b.empty()) return stack_a.top();//for 1 element case which data will store in stack_a;
	}
		
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T &element)
{
	// write your code here
	// std::stack<T> stack_c=stack_a;
	// std::stack<T> stack_d;
	// while(!stack_c.empty()){
	// 	stack_d.push(stack_c.top());
	// 	stack_c.pop();
	// }
	// stack_d.push(element);
	// while(!stack_d.empty()){
	// 	stack_c.push(stack_d.top());
	// 	stack_d.pop();
	// }
	// stack_a=stack_c;
	stack_b.push(element);//add data so no need to check if it is empty or not
}

template <typename T>
void CP::stack<T>::pop_bottom()
{
	// write your code here
	// std::stack<T> stack_c=stack_a;
	// std::stack<T> stack_d;
	// while(!stack_c.empty()){
	// 	stack_d.push(stack_c.top());
	// 	stack_c.pop();
	// }
	// stack_d.pop();
	// while(!stack_d.empty()){
	// 	stack_c.push(stack_d.top());
	// 	stack_d.pop();
	// }
	// stack_a=stack_c;
	if (stack_b.empty())
	{
		balanceStack(stack_a,stack_b,1,true);// same logic as pop()
	}
	else
	{
		stack_b.pop();
		if (stack_b.empty())
			balanceStack(stack_a, stack_b, 0, true);
	}
}
#endif