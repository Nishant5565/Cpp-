// ! Menu Driven Program for Circular Queue using arrays.

// Note - why we need circular queue and what is the differnece between these two - 

// *  Normal Queue:
// ? In a normal queue, once the elements are removed, the space cannot be reused. If the last position is reached, no more data can be inserted, even if there is space at the beginning of the queue. This issue is known as "Queue Overflow". To overcome this, we need to shift elements every time a dequeue operation is performed, which is not efficient.


// * Circular Queue:
//?  In a circular queue, the last element points back to the first element making a circular link. So, when we perform an enqueue operation at the end of a queue and the front of the queue is empty, we can insert an element in the front of the queue. This action is beneficial in memory utilization as it overcomes the problem of queue overflow in normal queue.

#include <iostream>
using namespace std;


class CircularQueue {
     int* arr;
     int front, rear;
     
     int SIZE;
public:
     CircularQueue(int size) {
          this->SIZE = size;
          arr = new int[SIZE];
          front = rear = -1;
     }

     void enqueue(int value){
          if ((rear + 1) % SIZE == front) {
               cout << "Queue overflow" << endl;
               return;
          }
          if (front == -1) {
               front = 0;
          }
          rear = (rear + 1) % SIZE;
          arr[rear] = value;
     }

     void dequeue() {
          if (front == -1) {
               cout << "Queue underflow" << endl;
               return;
          }
          if (front == rear) {
               front = rear = -1;
          } else {
               front = (front + 1) % SIZE;
          }
     }

     int peek() {
          if (front == -1) {
               cout << "No elements in Queue" << endl;
               return -1;
          }
          return arr[front];
     }

     bool empty() {
          return (front == -1);
     }

     void print() {
          if (front == -1) {
               cout << "No elements in Queue" << endl;
               return;
          }
          int i = front;
          while (i != rear) {
               cout << arr[i] << " ";
               i = (i + 1) % SIZE;
          }
          cout << arr[rear] << endl;
     }
};

int main() {

     int size;
     cout<< "Enter the size of the queue: ";
     cin >> size;
     CircularQueue q(size);
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

