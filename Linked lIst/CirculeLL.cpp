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
     ~Node(){
          int value = this->data;
          if(this->next!=NULL){
               delete next;
               this->next =NULL;
          }
          cout<< "Constructor called for value "<<value <<endl;
     }
};


void insertNode(Node* &tail, int data, int element){
     if( tail == NULL){
          Node * temp = new Node(data);
          temp->next = temp;
          tail = temp;
     }
     else{
          Node* curr = tail;
          while(curr->data!= element){
               curr = curr->next;
          }

          Node* temp = new Node(data);


     }
}

 int main(){
     
 }