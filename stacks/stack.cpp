#include <iostream>
using namespace std;

class Stack
{
     public:
     int *arr;
     int size;
     int top;
     Stack(int n)
     {
          size = n;
          arr = new int[size];
          top = -1;
     }
     void push(int x)
     {
          if (top == size - 1)
          {
               cout << "Stack Overflow" << endl;
               return;
          }
          top++;
          arr[top] = x;
     }
     void pop()
     {
          if (top == -1)
          {
               cout << "Stack Underflow" << endl;
               return;
          }
          top--;
     }
     int Top()
     {
          if (top == -1)
          {
               cout << "Stack is Empty" << endl;
               return -1;
          }
          return arr[top];
     }
     bool empty()
     {
          return top == -1;
     }

};


int main(){
     return 0;
     Stack st(3);
     st.push(1);
     st.push(1);
     st.push(1);
     st.push(1);
}