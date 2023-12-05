#include <iostream>
using namespace std; 

int insertionSort( int arr[] , int n){
     for(int i = 1; i<n ; i++){
          int temp = arr[i];
          int j= i-1;
          for(;j>=0;j--){
               if( arr[j]> temp){
                    arr[j+1] = arr[j];
               }
               else{
                    break;
               }
          }
          arr[j+1] = temp;
     }
}

int main(){
     
     int n;
     cout << "Enter the size of the array\n";
     cin>>n;
     int arr[n];
     cout<< "Enter the elements of the Array\n";
     for ( int i = 0;i<n ;i++){
          cin>>arr[i];          
     }
     cout << "Original Array is: ";
     int size = sizeof(arr)/sizeof(arr[0]);
          for(int i = 0 ;i<size;i++){
          cout<<arr[i]<<" ";
     }
     insertionSort(arr, size);
     cout <<"\nSorted array is: ";
     for(int i=0; i<size;i++){
          cout<<arr[i] <<" ";
     }
}