// ! Finding the first and last occurence of an element in an array by using binarySearch.

#include <iostream>
#include <vector>
using namespace std;

//! LOGIC-

// ? We make a variable ans which stores the index because we may have to update the value of mid index. We then find the mid index and we will now compare with the target value, if the target vlaue matches with the mid value then we will update the ans with this index also we have to check whether this is the first occurence or not, so for this we obviously need to check it on the left side, since first occurence can only be in the left side if the mid element is equal to the target value, if the target value is not equal to the mid value then it will check whether the value is greater than the target value or smaller than target value, after then we will update the start or end values according to our conditions. 


int firstOccurence(vector<int> arr, int target){
     int ans = -1;
     int s =0;
     int e = arr.size()-1;
     int mid = s + (e-s)/2; //? so the mid value in our case will be 0 + (8-0)/2 = 4, so our mid index is 4.
     while (s<=e){
          if (arr[mid] == target){
               // ? Here we checked if our array mid value which is 7 ( arr [4] = 7) is equal to our target value which is also 7  ( arr= {1,3,7,7,7,7,8,9}). Note we have passed target value already as an arguement in the main function.

               ans=mid; //? So we have update our ans variable.
               e=mid-1;//? But may be this is not the first occurence so we will update the end to mid -1, so that the loop checks if there is any first occurrence in the left side or not.
          }
          else if(arr[mid]>target){//? if our target value is greater than mid, then we have to check on the left side w.r.t mid.
               e = mid-1; 
          }
          else{ //? if our target value is smaller than mid, then we have to check on the right side w.r.t mid.
               s = mid+1;
          }
          mid = s + (e-s)/2;  //? updating the mid value, else our code will stuck in infinite loop or give error as we have updated the start and end but not the mid.
     }
     return ans;

}

// ? we also made a function for last occurence, here we will check on the right side if our mid element is equal to target element, the approach is same as firstOccurrence.  

int lastOccurence(vector<int> arr, int target){

     int ans = -1;
     int s=0;
     int e= arr.size()-1;
     int mid = s+(e-s)/2;
     while (s<=e){
          if(arr[mid]==target){
               ans=mid;
               s = mid +1;
          }
          else if (arr[mid]<target){
               s = mid +1;
          }
          else{
               e= mid-1;
          }

          mid = s+(e-s)/2;
     }

     return ans;

}

int main(){
     vector<int>v{1,3,7,7,7,7,8,9};
     int target = 7;
     int indexOfFirstOcc = firstOccurence(v,target);   
     int indexOfLastOcc = lastOccurence(v,target);   
     // cout<<v.size() <<endl;
     if(indexOfFirstOcc == -1){
          cout<<"Element not Found" <<endl;
     }
     else{
          cout<< "First occurencce of our element found at index " << indexOfFirstOcc << endl;
     }
     if(indexOfLastOcc == -1){
          cout<<"Element not Found";
     }
     else{
          cout<< "Last occurencce of our element found at index " << indexOfLastOcc <<endl;
     }

     cout << "Total occurrence of number "<< target << " is "<< indexOfLastOcc-indexOfFirstOcc+1;
}