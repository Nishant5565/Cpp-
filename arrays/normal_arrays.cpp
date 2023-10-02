#include <iostream>
using namespace std;

// ! How to make an array 
int main(){
     int arr[]={1,2,3,4,5,6};
     int size = 6;
     for(int i = 0;i<=size-1;i++){
          cout<<arr[i]<<endl;
          // ! we can also write the array by using dereference operator like this - *(arr+i)
          // ! or we can aslo write something i[arr], behind the scenes these are priniting the values by using deference operator.
     }
}