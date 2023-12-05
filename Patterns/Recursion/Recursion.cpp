#include <iostream>
using namespace std;

int factorial(int n){
     if(n==1){
          return 1;
     }
     int ans = n * factorial(n-1);
}


int main(){
     int n;
     cout << "Enter a number: ";
     cin >> n;
     int ans = factorial(n);
     cout << ans ;
     return 0;
}