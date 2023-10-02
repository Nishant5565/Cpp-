#include <iostream>
using namespace std;
int main(){
     // ? Pattern Hollow Diamond

     // * Explanation - The program prompts the user to enter an integer value, which is stored in the variable n. The program then uses nested for loops to print the diamond pattern. The outer loop iterates n times, and the inner loops print spaces and asterisks to form the diamond pattern. The first inner loop prints spaces before the asterisks, and the second inner loop prints the asterisks. The if-else statement inside the second inner loop is used to print asterisks only at the beginning and end of each row, and spaces in between. Finally, the program prints a newline character to move to the next row.

     int n;
     cin>>n;
     for(int i=0; i<n;i++){
          for(int j= 0 ; j<n-1-i;j++){
               cout<<" ";
          }
          for(int j=0; j<(2*i+1);j++){
               if(j==0 || j==2*i){
                    cout<<"*";
               }else{
                    cout<<" ";

               }
          }
          cout<<endl;
     }


}