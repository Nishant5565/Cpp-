#include <iostream>
using namespace std;


class Game{

     // ?  Access Modifiers - Thier are 3 type of access modifiers - Public, Private and Protected. By default it is set to private.

     int id;  //? As we have not mention any thing so our id variable is private, meaning you cannot access in other functions.

     public:  //? all the below varibales are accessible by any function.

     int hp ;
     int level = 10;
     int finishes;

     //! Constructors 
     //? there are two type of constructors Non parameterised and parametrised constructor. If we don't create any consstructor them by default a constructor is created by the compiler with no parameters and no return value. Once you created a constructor then the default constructor is no longer available.


     // * Non-Parameterised constructor- No parameters are passed while creating an object.

     Game(){
          cout<<"this is a Non parametrised constructor \n";
     }

     // * Parameterised constructor- Parameter should be passed while creating an object.

     Game(int level){
          cout<< "Parameterised Constructor called"<<endl;
          // cout<<"Level that we passed in the constructor "<<level <<"\n";
          //? Here the level is represting the parameter passed while creating the object.

          // cout<<"Main level of the object "<<this->level<<endl;
          //? whereas this->level is represting the level variable of the class, that we have created above
          // * So the thing is that this is actually a pointer which have the address of our object, so by deferencing it we can access the object values. Address of this and address of your object will be same, you can try as well.
          cout<<"Adress of this is optr "<<this<<endl;
          this->level = level;    //* Alternative way - 
          // cout<<"By using dereference operator "<<(*this).level<<"\n";

          

     }

     // ! Getter and Setters- Suppose we have some private properties in our object then to access these propeties we use getter and setters.
     // ? here we are just returning the value of id.
     int getId(){
          return id;
     }
     // ? so if we call this function with the parameter we can set the value of our id;
     int setId(int param){
          id = param;
     }

     // ! Destructors - we use destructor for memory deallocation.
     // ? Note - Destructors are also present by default just like constructors, but we can add our own destructor, but if we make our object statically then the user defined destructor will not call, the user defined destructor will only called when the object is made dynamically.

     // * The syntax of destructor is just like constructor the only difference is we add a tilde sign(~) for differentiation.
     ~Game(){
          cout<< "Destructor is called ";
     }

};

int main(){

     // ? Thier are two ways to create a object in a class, the first way allocates the memory statically.

     // Game Player1;  

     // Note in this case the non parameterised constructor will be called.

     // Note- if you're using the first way then to access the properties of the class you simply have to use dot(.) operator. For example- Player1.level; Now if you want to update or set the value then we write something like this - Player1.level = 20; 


     // ? The second way is the dynamic way where the memory allocates in the heap.

     Game *Player2 = new Game(20); 
     cout<<"Address of Player2 is "<<Player2<<endl;

     // ? In this way we created a object using a pointer named as Player2.

     // Note - Now when we create a pointer then accessing the value is quite a bit different from the first way, rather then using dot(.) operator we use arrow or dereference operators.
     // ? By using derefernce operator - The logic is we have created a pointer, so to access it's value we use * operator, Player2 is pointing the address of the object so obviously *Player2 will give the object, and now just like we earlier did, by using dot(.) operator we can access or update the values of the class. 

     (*Player2).finishes = 20;

     //* But this method is quite confusing for those who don't have clarity about pointers so to avoid using the derefernce operator we use -> arrow operator.

     cout<<"Finishes of player 2 is "<<Player2->finishes;
     cout<< "\nLevel is "<<Player2->level<<endl;

// ! Using getters and setters- 

     Player2->setId(12543726);
     cout<<"Player id is " <<Player2->getId();

// ! Copy constructors and other topics are in oopsContinue.cpp file.
}
