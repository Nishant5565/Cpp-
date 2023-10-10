#include <iostream>
using namespace std;
class Node{
     public:
     int data;
     Node* next;
     Node(int value){
          this->data = value;
          this->next=NULL;
     }
};
int main(){
     
     Node* List1 = new Node(10);
     cout<<List1-> data<<endl;
     cout<<List1->next<<endl;


}