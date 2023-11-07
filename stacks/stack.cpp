#include <iostream>
using namespace std;

class Node {
public:
     int data;
     Node* next;
};

class Stack {
private:
     Node* top;
public:
     Stack() : top(NULL) {}

     void push(int data) {
          Node* temp = new Node();
          if (!temp) {
               cout << "\nHeap Overflow";
               exit(1);
          }
          temp->data = data;
          temp->next = top;
          top = temp;
     }

     bool isEmpty() {
          return top == NULL;
     }

     int peek() {
          if (!isEmpty())
               return top->data;
          else
               exit(1);
     }

     void pop() {
          if (top == NULL) {
               cout << "\nStack Underflow" << endl;
               return;
          }
          Node* temp = top;
          top = top->next;
          temp->next = NULL;
          delete temp;
     }

     void display() {
          Node* temp;
          if (top == NULL) {
               cout << "\nStack Underflow";
               exit(1);
          }
          else {
               temp = top;
               while (temp != NULL) {
                    cout << temp->data << "-> ";
                    temp = temp->next;
               }
          }
     }
};

int main() {
     Stack s;
     s.push(10);
     s.push(20);
     s.push(30);
     s.display();
     cout << "\nTop element is " << s.peek() << endl;
     s.pop();
     s.display();
     return 0;
}