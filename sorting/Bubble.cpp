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
     int arr[6] = {10,1,7,6,14,9};
     int size = sizeof(arr)/sizeof(arr[0]);
     bubbleSort(arr, size);
     for(int i = 0 ;i<size;i++){
          cout<<arr[i]<<" ";
     }
}