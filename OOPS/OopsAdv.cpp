#include <iostream>
using namespace std;

// ! Encapsulation - 
// ? Wrapping up functions and data members, fully encapsuled class is the class in which all the Data members are private.
// * Advantages of Encapsulation - Data hiding, Code Reusability and readablity.

class Human{
     public:
     int height;
     int weight;
     int age;

     public:
     int getAge(){
          return age;
     }
     int setWeight(int x){
          this->weight = x;
     }
};

// ! Inheretance -  
// ? Inheritance means one class can inherit the properties of another class, Adding new features to an existing class without modifying it.

class Male: public Human{
     public:
     string color;
     
};

int main(){

}