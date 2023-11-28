// ! Menu Driven Program for queues using arrays.

// * It uses the FIFO login, meaning first in first out { the element which is inserted first will also be deleted as first.}

#include <iostream>
using namespace std;


class Queue {
     int* arr;
     int front, back;

public:
     Queue(int SIZE) {
          arr = new int[SIZE];
          front = -1;
          back = -1;
     }

     void enqueue(int value , int SIZE) {
          if (back == SIZE - 1) {
               cout << "Queue overflow !!!! current queue is" << endl;
               print();
               return;
          }
          arr[++back] = value;
          if (front == -1) {
               ++front;
          }
     }

     void dequeue() {
          if (front == -1 || front > back) {
               cout << "Queue underflow !!!! current queue is " << endl;
               return;
          }
          ++front;
     }

     int peek() {
          if (front == -1 || front > back) {
               cout << "No elements in Queue" << endl;
               return -1;
          }
          return arr[front];
     }

     bool empty() {
          return (front == -1 || front > back);
     }

     void print() {
          if (front == -1 || front > back) {
               cout << "No elements in Queue" << endl;
               return;
          }
          for (int i = front; i <= back; i++) {
               cout << arr[i] << " ";
          }
          cout << endl;
     }
};

int main() {
     int size;
     cout<< "Enter the size of the queue: ";
     cin >> size;
     Queue q(size);
     int choice, value;
     do {
          cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Print Queue\n6. Exit\n";
          cout << "Enter your choice: ";
          cin >> choice;
          switch(choice) {
               case 1: cout << "Enter value to enqueue: ";
                         cin >> value;
                         q.enqueue(value , size);
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