#include <iostream>
using namespace std;

int binarySearch(int arr[], int element){
     int start = 0;
     int end = 8;
     int mid = (start+end)/2;
     while(start<=end){
          if(arr[mid] == element){
               return mid;
          }
          else if (arr[mid] > element ){
               end = mid;
          }
          else {
               start = mid;
          }
          mid = (start+end)/2;
     }
     return -1;
}


int main(){
     int arr[10]={1,2,3,4,5,16,77,88,99};
     int element = 77;
     int result = binarySearch(arr, element);
     if( result == -1){
          cout<< "Not found "<< endl;

     }
     else{
          cout<< "Element found at index "<< result;
     }

}