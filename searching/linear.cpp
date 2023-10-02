#include <iostream>
using namespace std;

int main(){
     int arr[] = {1,2,3,4,5,10,23,422,444345,413,133,4141,4,1,5,1,4113};
     int size = sizeof(arr)/sizeof(int);
     int num = 4113;


     // ? Linear search is a pretty simple search, we just check our target element into the array one by one, for that we make a loop, obviously from 0 to last index, and comparing each element with our target value.
     for( int i = 0; i<size; i++){
          if ( arr[i] == num){
               cout<<"found at index " << i;
          }
     }


     // ! Now why is Binary Search is better way then doing linear search?                                                                   So the simple answer is time and space complexity, suppose we have 10,000 elements in our array, now linear search will run the loop thousand times making the T&S complexity O(n). Now the same operation in Binary search needs only 10 comparisons as 2^10 is 1024         T&S = O(logn) here our log's base is 2. 

}