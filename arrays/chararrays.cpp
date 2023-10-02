#include <iostream>
using namespace std;

// ! Char arrays - Character can be anything, a,b,c... or 1,2,3, or -<+ etc. Char arrays can store any character, it takes 1 byte of data.It is a datastructure. In character arrays you can take a single character as an input or an entire sequence of characters. It creates a null character at the end of the string by default. Suppose we give input -> Nishant then from index 0 to 6 Nishant will be stored but a null character get itself automatically at index 7, which terminates the string at that index. The ASCII value of null character is 0.

int main(){
     char ch[100];   //? Creating a character array with 100 characters.
     // cin>> ch;  //? Now we can pass up to 100 characters, you can even pass a string like - Nishant.
     // cout<<ch;  // Note- Unlike normal arrays, char arrays will give the value of array rather then giving the address of the array. 

     // * Note if we try to insert some space or tab or a newline character then the char array stops taking input and places the null character. For example if we try to input - Hello World, and if we output the char array then only Hello will be printed. For this issue the solution is to use -->>  cin.getline() function. It takes three parameters, first is the name of the char array, second lenght/number of char to take inputs, third delimiting character, means the operation of extracting successive characters stop as soon as the next character to extract compares equal to this, by defalut the delim is set to \n ( the newline character).

     cin.getline(ch, 100 , '$'); //? it will take 10 characters, and if we pass $ then it will stop taking input. 
     cout<<ch;
     return 0; 


     // ! Questions and extra stuffs about char arrays is in CharQuestions.cpp file.
     
}

