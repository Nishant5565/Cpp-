// ! Menu Driven Program for stacks using arrays.


#include <iostream>
using namespace std;


class Stack {


public:
     int* arr;
     int top;
     int size;

     

     Stack(int size) {
          this->size = size;
          arr = new int[size];
          top = -1;
     }

     void push(int value) {
          if( size-top>1){
               top++;
               arr[top] = value;
               cout<< "\nValue pushed -> "<< value;
               cout<< "\nCurrent Stack is: ";
               print();
          }
          else{
               cout << "\nStack Overflow !!! Current Stack is: ";
               print();
               
          }
     }

     void pop() {
          top--;
     }

     int peek() {
          return arr[top];
     }

     bool empty() {
          if(top>=0){
               return false;
          }else{
               return true;
          }
     }

     void print() {
          if ( empty()){
               cout << "Stack is empty";
               return;
          }
          else{
               for ( int i = 0; i<= top; i++){
               cout << arr[i] << " ";
          }
          cout << endl;
          }

     }
};

int main() {
     cout << "Enter size of the Stack: ";
     int size;
     cin>>size;
     Stack st(size);
     int choice, value;
     do {
          cout << "\n1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Print Stack\n6. Exit\n";
          cout << "Enter your choice: ";
          cin >> choice;
          switch(choice) {
               case 1: cout << "Enter value to push: ";
                         cin >> value;
                         st.push(value);
                         break;
               case 2: st.pop();
                         break;
               case 3: cout << "Top element is: " << st.peek() << endl;
                         break;
               case 4: if(st.empty()){
                              cout << "stack is empty ";
                         }
                         else{
                              cout << "stack is not empty ";
                         }
                         break;
               case 5:   cout<< "\nStack is: ";
                         st.print();
                         break;
               case 6: cout << "Exiting...";
                         break;
               default: cout << "Invalid choice!";
          }
     } while(choice != 6);

     return 0;
}