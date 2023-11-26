#include <iostream>
using namespace std;
class Node{
     public:
     int data;
     Node* next;
     Node(int data){
          this->data= data;
          this->next= NULL;
     }

     //? In this destructor, the first line int value = this->data; is storing the value of the node's data in a local variable value. The this keyword is a pointer that points to the current object.

     //? The next line if(this->next!=NULL) is checking if the next pointer of the current node is not NULL. If it is not NULL, then the destructor is called recursively for the next node. This is done by calling delete next;

     // ? The last line this->next =NULL; is setting the next pointer of the current node to NULL. This is done to avoid the dangling pointer problem. If we do not set the next pointer to NULL, then the next pointer of the current node will still be pointing to the next node even after the current node is deleted. This will cause problems when we try to access the next pointer of the current node in the destructor of the next node.

     ~Node(){
          int value = this->data;
          if(this->next!=NULL){
               delete next;
               this->next =NULL;
          }
          cout<< "Constructor called for value "<<value <<endl;
     }
};

void insertNode(Node* &tail, int data){
     if(tail == NULL){

     }
}


 int main(){
     // insertNode();
 }