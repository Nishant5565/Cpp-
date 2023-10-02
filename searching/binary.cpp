#include <iostream>
using namespace std;

// ? Logic of Binary Search ->                                                                                                                Binary search looks for a particular item by comparing the middle most item of the collection. If a match occurs, then the index of item is returned. If the middle element is greater than the target value, then the target value is searched in the sub-array to the left of the middle element, and right if the middle element is smaller than the target value and this search will keep on until our middle elements becomes the target value.  

// ! Array should be sorted.


int binarySearch(int arr[], int size , int target){
     int start,mid,end;
     start = 0; //? Starting index
     end = size-1; //? Last index
     mid = (start+end)/2;  //? index of the mid element.  Note- since we are dividing an integer (start + end) with an integer (2) our result will also be an integer following the greatest integer rule( suppose our the division comes 6.5 then by GIF the result will be 6 ).

     // ! Integer Overflow Issue while finding the Sum.
     // ? So their is an issue in this formula, as the integer can overflow beacause the integer datatype has a range from -2^31 to 2^31-1. Note that our start and end will always comes in the range otherwise we have to change the datatype, but our sum (start + end ) can exceed the range, that's why we should modify the formula like this {start -s and end -e }  =>[ mid = (s +(e-s)/2) ], now if you solve this further you will get => s + e/2 -s/2 => (s+e)/2, which is the same but in this fromula the value don't exceed the range, as we first subtracting s from e.

     while (start <=end){   //? This loop will run until our end = start value, after than the start will be greater than end.

     // ! Note - everytime the loop runs, the array size becomes half.
          //? Here we store the arr[mid] value into an element named midElement for convinience (Note - this value updates every time till our midElement == target).

          int midElement = arr[mid];  
          
          if (midElement == target)  
          {

               //? we checked if our mid element is the element we are searching, if yes then return the index, and the value updates after each cycle.

               return mid;
          }
          else if(target < midElement){
               //? if the midElement is greater than the element that we are searching for, then we just have to search for the left side wrt the mid number, hence updating the end with mid -1( Note - as the mid is not the element that we are searching then we can ignore this for better time and space complexity).

               end = mid-1 ;  
          }
          else{
               //? if the midElement is smaller than the element we are searching for, then we have to update our start with mid, hence searching only the right side, again mid + 1 because of better time and space complexity.

               start = mid +1;
          }

          mid = (start+end)/2;  //? here we are updating our mid each time the if condition fails.
     }

     // ! if the element is not found then the function will give -1 index( an invalid index).

     return -1;
}

int main(){
     int arr[]= {1,2,3,4,7,8,9,12,14,21,344,345,564};
     int size = 13;
     int target = 564;

     // ? Here we store the value in searchResult variable that we got from the function binarySearch.

     int searchResult = binarySearch( arr, size, target);
     if (searchResult == -1){
          cout << "Not found"; 
     }
     else{
          cout<< "Element found at index "<< searchResult; 
     }

}