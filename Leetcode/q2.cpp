#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Enter the no. of elements : ";
  cin >> n;
  int data[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter the element :";
    cin >> data[i];
  }
  int k;
  cout<<"enter the no. to be searched : ";
  cin>>k;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (data[i] == k) {
            cout << "Record found at position " << i << '\n';
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found.\n";
    }
     return 0;
}