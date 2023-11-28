// ! Menu Driven Program for Queue using Linked List

#include <iostream>
using namespace std;

struct Node {
     int data;
     Node* next;
};

class Queue {
     Node *front, *rear;

public:
     Queue() {
          front = rear = NULL;
     }

     void enqueue(int value) {
          Node* temp = new Node;
          temp->data = value;
          temp->next = NULL;
          if (front == NULL) {
               front = rear = temp;
               return;
          }
          rear->next = temp;
          rear = temp;
     }

     void dequeue() {
          if (front == NULL) {
               cout << "Queue underflow" << endl;
               return;
          }
          Node* temp = front;
          front = front->next;
          if (front == NULL) {
               rear = NULL;
          }
          delete temp;
     }

     int peek() {
          if (front == NULL) {
               cout << "No elements in Queue" << endl;
               return -1;
          }
          return front->data;
     }

     bool empty() {
          return (front == NULL);
     }

     void print() {
          if (front == NULL) {
               cout << "No elements in Queue" << endl;
               return;
          }
          Node* temp = front;
          while (temp != NULL) {
               cout << temp->data << " ";
               temp = temp->next;
          }
          cout << endl;
     }
};

int main() {
     Queue q;
     int choice, value;
     do {
          cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Print Queue\n6. Exit\n";
          cout << "Enter your choice: ";
          cin >> choice;
          switch(choice) {
               case 1: cout << "Enter value to enqueue: ";
                         cin >> value;
                         q.enqueue(value);
                         break;
               case 2: q.dequeue();
                         break;
               case 3: cout << "Front element is: " << q.peek() << endl;
                         break;
               case 4: if(q.empty()){
                              cout << "Queue is empty ";
                         }
                         else{
                              cout << "Queue is not empty ";
                         }
                         break;
               case 5: q.print();
                         break;
               case 6: cout << "Exiting...";
                         break;
               default: cout << "Invalid choice!";
          }
     } while(choice != 6);

     return 0;
}