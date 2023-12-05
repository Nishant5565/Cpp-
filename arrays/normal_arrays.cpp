#include <iostream>
using namespace std;

int top = -1;

void push(int x , int arr[], int n) {
     if (top >=n-1) {
          cout << "Overflow!!!" << endl;
     } else {
          top++;
          arr[top] = x;
     }
}

void pop(int arr[]) {
     if (top < 0) {
          cout << "Underflow!!!!" << endl;
     } else {
          cout << "Popped element: " << arr[top] << endl;
          top--;
     }
}

void print(int arr[]) {
     for (int i = 0; i <= top; i++) {
          cout << arr[i] << " ";
     }
     cout << endl;
}

int main() {
     int n;
     cout << "Enter the size of the array: ";
     cin >> n;
     int arr[n];
     int choice, x;
     do {
          cout << "1. Push\n2. Pop\n3. Print\n4. Exit\nEnter your choice: ";
          cin >> choice;
          switch (choice) {
               case 1:
                    cout << "Enter the element to be pushed: ";
                    cin >> x;
                    push(x , arr , n);
                    break;
               case 2:
                    pop( arr);
                    break;
               case 3:
                    cout << "The array is: ";
                    print(arr);
                    break;
          }
     } while (choice != 4);
     return 0;
}