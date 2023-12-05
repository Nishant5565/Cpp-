#include <iostream>
using namespace std;
int selectionSort(int arr[], int n){

     for( int i =0; i< n-1; i++ ){

          int minIndex = i;
          for( int j = i+1;j <n ;j++ ){
               if(arr[j] < arr[minIndex]){
                    minIndex = j;
               }

          }
          swap(arr[i], arr[minIndex]);
     }

}

int main(){
     int arr[] = {10,23,54,42,84,1,52,23};
     int n = 8;
     selectionSort(arr , n);

     for(int i=0; i < n ;i++){
          cout << arr[i]<<" ";
     }
}