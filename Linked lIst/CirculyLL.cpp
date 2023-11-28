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

//* Case 1 - no node is present, then create a node which is pointing to itself.
//* Case 2 - if a node is already present than it means already it have a tail and it is pointing to the head, so we need to store the pointer's value.



// * Function insert after that particular position
void insertNode(Node* &tail, int element,int data){
     if(tail == NULL){
          Node* temp = new Node(data);
          temp->next = temp;
          tail = temp;
          cout<< " adress of temp is " << temp->next <<endl;
     }
     else {

          Node * curr = tail;
          while ( curr->data != element ){
               curr = curr->next;
          }

          Node* temp = new Node(data);
          temp->next = curr->next;
          curr->next = temp;

     }
}


// * Traversing a linked list 

void print(Node* tail){

     Node * curr = tail;
     do
     {
          cout << curr->data<< " ";
          curr = curr->next;
     } while (curr != tail);
}

 int main(){
     Node * tail = NULL;
     insertNode( tail ,10, 20 );
     insertNode( tail ,20, 50 );
     insertNode( tail ,20, 60 );
     insertNode( tail ,20, 30 );
     print(tail);
 }