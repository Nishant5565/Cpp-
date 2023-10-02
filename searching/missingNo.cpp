#include <iostream>
#include <vector>
using namespace std;


int missingFunction(vector<int> arr){

     int s =0;
     int ans = -1;
     int e =7;
     int mid= (s+e)/2;     
     while(s<=e){

          if(arr[mid]!=(mid+1)){
               ans = arr[mid];
               e=mid-1;
          }
          else if(arr[mid] == mid+1){
               s=mid+1;
          }
          else{
               e=mid-1;
          }
          mid=(s+e)/2;
     }
     return ans;

}


int main(){
     vector<int> v{1,2,3,4,5,6,7,8,9};
     int missingNumber = missingFunction(v);
     if(missingNumber == -1){
          cout<<"Eveything is fine";

     }else{ 
          cout<<"The number which is missing is "<<missingNumber-1;
     }
}