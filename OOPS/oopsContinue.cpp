#include <iostream>
using namespace std;

class Hero{
     public:
     char Health;
     int level;
     int finishes;
     Hero(int level){
          this->level = level;
     }
};


int main(){

     Hero Nishant(20);
     cout<<Nishant.level;

}