#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n; //No of rows.
    int a =5;

    // Note - comment in the codes to run the program.

    //? For normal triangle pattern

    // * Explaination - The outer loop iterates from 0 to n-1, where n is the number of rows in the pattern. The inner loop iterates from 0 to i, where i is the current row number. In each iteration of the inner loop, an asterisk is printed to the console. After the inner loop completes, a newline character is printed to move to the next row. This pattern creates a right-angled triangle of asterisks, where the number of asterisks in each row increases by 1.

    /*for(int i = 0;i<n;i++){
        for(int j=0; j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/

    //? For inverted triangle pattern

    /*for(int i =0;i<n;i++){
        for(int j=n;j>i;j--){
            cout<<"*";
        }
        cout<<endl;
    }*/

    //! Alternative Code for inverted triangle pattern:
    /*for(int i=0;i<n;i++){
        for(int j=0; j<(n-i);j++){
            cout<<"*";
        }
        cout<<endl;
    }*/
    

    //? Numeric Half Pyramid

    /*for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<j+1;
        }
        cout<<endl;
    } */   
    
    //? Full pyramid pattern 
    /*for(int i=0;i<n;i++){
        for(int j=0;j<(n-i-1);j++){
            cout<<" ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
        
    }*/
    //? Inverted Full pyramid pattern
    /*for (int i = 0; i < n; i++)
    {
        for (int j= 0;j<i;j++)
        {
            cout << " ";
        }
        for (int j = 0; j <n-i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }*/

    cout<<(++a)*(++a);

}