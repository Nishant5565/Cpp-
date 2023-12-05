#include <iostream>
using namespace std;


// Note-  The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. This algorithm maintains two subarrays in a given array. The steps are as follows: 
//* 1. Find the minimum element in the unsorted part of the array
//* 2. Swap the found minimum element with the first element of the unsorted part
//* 3. Repeat the steps until the entire array is sorted

// ? Exapmle: 64 25 12 22 11 --> 11 25 12 22 64 --> 11 12 25 22 64 --> 11 12 22 25 64 --> 11 12 22 25 64


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        //* Find the minimum element in the unsorted part of the array
        //* Assume the current index is the minimum
        int minIndex = i;

        //* Iterate through the unsorted part to find the real minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        //* Swap the found minimum element with the first element of the unsorted part 
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
     int n;
     cout << "Enter the size of the array\n";
     cin>>n;
     int arr[n];
     cout<< "Enter the elements of the Array\n";
     for ( int i = 0;i<n ;i++){
          cin>>arr[i];          
     }
    int x = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    selectionSort(arr, x);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
