#include <iostream>
using namespace std;
int bubbleSort(int arr[] , int n){
     bool swapped = false;
     for(int i = 0; i<n-1 ; i++){
          for(int j = 0; j< n-1-i; j++){
               if(arr[j]> arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    swapped = true;
               }
          }
          if (swapped == false){
               break;         
          };
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
     
     bubbleSort(arr, size);
     cout<<"\nSorted array is :";
     for(int i = 0 ;i<size;i++){
          cout<<arr[i]<<" ";
     }
}