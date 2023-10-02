#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n; //No of rows.
    int a =5;

    //? For normal triangle pattern

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