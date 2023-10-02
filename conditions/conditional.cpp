#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout<<"Enter number of rows : ";
    cin>> n;
    cout<<"Enter number of coloumns : ";
    cin>> m;

    for(int i=0;i<n;i++){
        if(i==0 || i==n-1){
            for (int j=0;j<m;j++){
                cout<<"* ";
            }
            cout<<endl;
        }else{
            for(int j=0;j<m;j++){
                if( j==0 || j==m-1){
                    cout<<"* ";
                    if(j==m-1){
                         cout<<endl;

                    }                
                }
                else{
                    cout<<"  ";
                }
                
            }
        }
    }
}
