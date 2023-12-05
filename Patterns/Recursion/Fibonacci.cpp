#include <iostream>
using namespace std;

// * The function takes three parameters: n (the number of terms to print), a (the current term, initially 0), and b (the next term, initially 1). The function prints the current term, then calls itself with n - 1, b, and a + b as the new parameters, the recursion stops when n becomes 0.

void printfibonacci(int n, int a = 0, int b = 1) {
     if (n == 0) {
          return;
     }
     cout << a << " ";
     printfibonacci(n - 1, b, a + b);
}

int fibonacci(int n) {
     if (n == 0 || n == 1) {
          return n;
     }
     return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
     int n;
     cout << "Enter the nth term you want to find: ";
     cin >> n;
     cout << "Fibonacci series up to " << n << " terms: ";
     printfibonacci(n);
     
     // int ans = fibonacci(n);
     // cout << "\n" << n << "th term of the fibonacci series is: " << ans;

     return 0;
}