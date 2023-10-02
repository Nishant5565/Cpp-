// ! We can use pre defined Binary search function that is present in our sdl - Standard Template Library, we can also use this sdl to obtain first occurrence and last occurrence.
 #include <iostream>
 #include <algorithm>  //? Importing the algorithm file that includes the binary_search algorithm.
 #include <vector> 
 using namespace std;
 //? Vector is a better way to make arrays and dynamic arrays.

 int main (){

     // ! Using normal array method to make array.
     int arr[]= {1,2,3,4,5,6,7,8,9};
     int size = 9;
     if(binary_search (arr , arr+size , 8)){
          cout<< "Found in normal array" <<endl;
     }
     else{
          cout<< " Not found in normal array" <<endl;
     }



     // ! Using vector to make array.

     vector<int> myarr{1,2,3,4,5,6,7,7,7,7,8,9};
     int target = 7;

     auto ans2= lower_bound(myarr.begin(),myarr.end(),target);
     auto ans3= upper_bound(myarr.begin(),myarr.end(),target);
     cout<< "Lower bound is "<<ans2-myarr.begin()<<endl;
     cout<< "Upper bound is "<<ans3-myarr.begin()<<endl;



     // ! Using Binary search 
     if(binary_search (myarr.begin(), myarr.end(), 4)){
          cout<< "Found in vector" << endl;
     }
     else{
          cout<< " Not found in vector" << endl;
     }
 }