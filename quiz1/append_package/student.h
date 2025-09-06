#include "stack.h"
#include "queue.h"
//ใช้ CP::stack อย่าใช้ std::stack เพราะเค้าไม่ได้ include ให้
//error ที่เจอ expected primary-expression before '>'


namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        CP::stack<T> temp;
        
        
        while(!empty()){
            temp.push(top());
            pop();
        }
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        while(!temp.empty()){
            push(temp.top());
            temp.pop();
        }

    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        CP::stack<T> temp1;
        CP::stack<T> temp2;
        while(!q.empty()){
            temp1.push(q.front());
            q.pop();
        }
        while(!empty()){
            temp2.push(top());
            pop();
        }
        while(!temp1.empty()){
            push(temp1.top());
            temp1.pop();
        }
        while(!temp2.empty()){
            push(temp2.top());
            temp2.pop();
        }
        
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while(s.empty()){
            push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            push(q.front());
            q.pop();
        }
    }
}
