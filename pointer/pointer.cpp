#include <iostream>
using namespace std;
int main(){
     // ? What is pointer, pointer is basically a variable in which we only store the address of another variable. We can access the address of a var by using & operator. NOTE- if we write *ptr then we can access the value stored at the address that our pointer is targetting.

     int a=5; //? So first of all we initialise a variable and assigned a value into it.

     int* ptr = &a; 
     cout<<ptr <<endl;   //? This will print the address of the variable a.
     cout<<*ptr;   //? This will print the value of the variable a which is in our case is 5.
     
     //! Now we created a pointer with name ptr,in which we stored the address of a, note you can only store addresses in a pointer, that's why no matter what datatype is of your pointer it will always take same no. of bits depending on your Computer system architecture. You can try as well by commenting out and running the below commands.

     /*
     char b ='a';
     char* p1 = &b;
     string c = "Hello";
     string* p2 =&c;

     cout<< "Size of b is "<< sizeof(b)<< ", Size of pointer b is "<< sizeof(p1) <<endl;
     cout<< "Size of c is "<< sizeof(c)<< ", Size of pointer c is "<< sizeof(p2) <<endl; */
     

     // ! This is all about pointers, lets move on to array vs pointer.

     cout<<"\n \nArrays part :  \n";

     //? Now you might have tried to print your array by passing the name of the array, Something like this:
     int myarr[10] = {1,2,3,4,5,6,7,8,9,0};

     cout << myarr;
     //? If you don't know then it will print the Base address of your array not the values.

     // ! So here comes the question, pointer also gives the adrress and arrays are also giving the adrress then what's the difference between those two? First of all let's have some questions on arrays and pointer. 


     // Todo- uncomment and run the code after figuring out the answers on your own, then after read next instructions.
     auto* arrp = &myarr;

    /* 
     cout<< "\n result of *arrp " << *arrp<<
     "\n result of arrp "<< arrp<<
     "\n result of myarr "<< myarr<<
     "\n result of *myarr "<< *myarr<<
     "\n result of myarr[0] "<< myarr[0]<<
     "\n result of myarr[1] "<< myarr[1]<<
     "\n result of *arrp + 1  "<< *arrp+1<<
     "\n result of *(arrp + 1) "<< *arrp+1<<endl
     ;  
     */


//! So as you can see if you try to get the values of *arrp and myarr then it will return the same address, even the myarr[0] is returning the same address since it is present on the base address, but let's see other results as well *arrp +1 is same to the address of myarr[1], so here comes an intersting concept, suppose our base address is at 208, so if we access the address by using the help of pointer and increment it with 1, then it doesn't means that we are accessing the address 209, rather than it will jump to address 212 since our integer datatype have 4bits (depends on your system). 

// ?Now if you try to do the same by using array, something like this - myarr= myarr+1, will it give the address of the next value? Actually no, we cannot update the address, in the case of pointers the address is stored as a value so we can update the values, but we can't directly change/update the address of a variable since it's the work of Operating System.
 
//? Arrays also works as pointer, so you can access their values similarly like we do in case of pointers, by using dereference operator, as you may have noticed *myarr (using deference operator on an array) and myarr[0] are returning the same values.


// ! Now for your knowlegde, arrays behind the scenes are using pointers to acces the values.

     int arr[]={1,2,3,4,5,6};
     int size = 6;
     for(int i = 0;i<=size-1;i++){


          //Todo - uncomment the code. 
          // cout<<arr[i]<<endl;

          // ? So behind the scenes this expression resolves like this -> *( arr + i), so everytime i increments, it goes to the next value.
          
          //! you can also write the array like this- 
          // cout << i[arr]<<endl;
          // ?it will also break something like this-> ( i + arr ) which is the same as (arr + i).

          // !you can also print the values by using only dereference operator, as you can access the array as a pointer.
          //  cout<< *(arr+i);
     }

}
