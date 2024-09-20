#include <iostream>
#include <vector>
using namespace std;

// ! Functions
// * Functions are a block of code that performs a specific task. Functions are used to break down large programs into smaller, more manageable pieces. Functions can be called multiple times from different parts of the program. Functions can take parameters and return values. Functions can be defined in any order in the program. Functions can be defined inside other functions. Functions can be defined in separate files and linked to the main program. Functions can be overloaded, which means that multiple functions can have the same name but different parameters. Functions can be recursive, which means that a function can call itself.

// ? Function Declaration
// * A function declaration tells the compiler about a function's name, return type, and parameters. A function definition provides the actual body of the function. Example: int add(); // function declaration

// ? Function with Parameters and Return Type
// * Functions can take parameters and return values. Parameters are the values passed to the function. Return values are the values returned by the function. Example: int add(int x, int y) { return x + y; } // function with parameters and return type

// ? Calling a Function with Parameters
// * To call a function with parameters, you need to pass the values of the parameters. Example: int sum = add(5, 3); this will return 8, also the values that are passed in the function are called arguments.



int main(){
    int arra[]= {1,2,3,4,5,6};
    int arrb[]={7,8,9,10};
    int sizea = 6;
    int sizeb= 4;
    vector<int> ans;
    for(int i = 0; i<sizea;i++){
        ans.push_back(arra[i]); 
    }    
    for(int i = 0; i<sizeb;i++){
        ans.push_back(arrb[i]); 
    }
    for(int i =0;i<ans.size();i++){
        cout<< ans[i] <<" ";
    }
}