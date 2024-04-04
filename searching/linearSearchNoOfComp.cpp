#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int k, int& comparisons) {
    for (int i = 0; i < n; i++) {
     comparisons++;
        if (arr[i] == k) {
            return i;
        }
    }
    return -1;
}

int main(){
        int n;
        cout << "Enter the size of the array: ";
        cin>> n ;
        int arr[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k;
        cout << "Enter the element to be searched from the array " <<endl; 
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        };
        cout << endl;
        cin >> k;
        int comparisons = 0;
        int index = linearSearch(arr, n, k , comparisons);
        if (index != -1) {
            cout << "Element found at index " << index << endl;
        } else {
            cout << "Element not found" << endl;
        }
        cout << "Total number of comparisons made: " << comparisons << endl;
        return 0;
}