#include <iostream>
#include <string.h>
using namespace std;




 // ! Question - find the length of your char array.
// ? To find the length of our char array we simply use linear search and search for our null character because it represents the end of the array. ( Note- Obviously the array's size is 100 in our case, but we are finding how many characters are present in our array.).

int charLength( char arr[]){



     int length=0;
     int i=0;
     while(arr[i]!= '\0'){  //* Here '/0' is the ASCII value of null character.
          length++;
          i++;

     }
     return length;
}

// ! Question - To reverse a string.
// ? Here the logic is to swap the starting and ending characters, for example suppose we take Nishant as input then if we swap N with T, I with N, S with A and H with H then our string will autommatically is reversed, to do so, we need a loop, intialising our start(i) with 0th index and end(j) with n-1, and we will update the value after each swap, incrementing our start index and decrementing our end index,  the loop stops when the starting index is greater than ending index.

int reverseChar(char arr[]){
     int i = 0;
     int n = charLength(arr);
     int j = n-1;
     while (i<=j)
     {
         swap(arr[i] , arr[j]);
         i++;
         j--;
     }
     
}

// ! Question - To replace spaces with some other character.
// ? Logic is pretty simple,by linear search we check if the character is a space or not, and if it is then replace with the special character.

void replaceSpaces( char sentence[]){
     int size = charLength(sentence);
     for(int i =0; i<size; i++){
          if(sentence[i] == ' '){
               sentence[i] = '@';
               
          }
     }
}


int main(){

// ! Answer 1

     char arr[100];
     cin >> arr;

     int charLen= charLength(arr); 
     cout<< "You have input " << charLen << " characters" << endl;

     // Note - there is also a predifined function which gives the length of char array -> strlen(), make sure that you have included the string.h file.

     cout<< "Number of characters by pre defined function "<< strlen(arr)<<endl;  


// ! Answer 2


     cout<< "Initially our array is "<< arr << endl;
     reverseChar(arr);   //! Since array is pass by reference so the changes will be sustain in the main function as well.
     cout<< "After reversal our array is "<< arr<< endl;

// ! Answer 3


     char myarr[100];
     cin.getline(myarr, 30);

     replaceSpaces(myarr);

     cout<< "Replacing the characters " << arr << endl;     
}