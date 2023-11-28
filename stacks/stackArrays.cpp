// ! Menu Driven Program for stacks using arrays.


#include <iostream>
using namespace std;

class Node {
public:
     int data;
     Node* next;
};

class Stack {
public:
     Node* top;

     Stack() {
          top = NULL;
     }

     void push(int value) {
          Node* newNode = new Node();
          if (!newNode) {
               cout << "Heap overflow";
               exit(1);
          }
          newNode->data = value;
          newNode->next = top;
          top = newNode;
     }

     void pop() {
          if (top == NULL) {
               cout << "Underflow" << endl;
               return;
          }
          Node* temp = top;
          top = top->next;
          temp->next = NULL;
          delete temp;
     }

     int peek() {
          if (!empty())
               return top->data;
          else
               exit(1);
     }


     bool empty() {
          return top == NULL;
     }

     void print() {
          Node* temp = top;
          while (temp != NULL) {
               cout << temp->data << "-> ";
               temp = temp->next;
          }
     }
};

int main() {
     Stack st;
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
               case 5: st.print();
                         break;
               case 6: cout << "Exiting...";
                         break;
               default: cout << "Invalid choice!";
          }
     } while(choice != 6);

     return 0;
}