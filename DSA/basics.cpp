// linear search 

#include <iostream>
using namespace std;

int linearSearch( int search, int arr[] ){
 
     for (int i =0; i <= 5; i++){
          if (search == arr[i]){
               return i;
          }
     }

     return -1;

}

int main(){
     int myArray[5] = {1,23,14, 18, 20};
     int element = 25;
     int result = linearSearch(element, myArray);
     cout << result;
}