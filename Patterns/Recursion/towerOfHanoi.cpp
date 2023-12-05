#include <iostream>
using namespace std;


// Note - It consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
//* Only one disk can be moved at a time.
//* Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
//* No disk may be placed on top of a smaller disk.


void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
     if (n == 1) {
          cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
          return;
     }
     towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
     cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
     towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
     int n;
     cout << "Enter the number of disks: ";
     cin >> n;
     towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
     return 0;
}