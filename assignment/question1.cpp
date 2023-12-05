#include<iostream>
using namespace std;


class Node{

public: 
int data;
Node* next ;

    Node (int data ){
     this->data = data;
     this-> next = NULL;
    }
};



void insertNode( int element, Node * &head) {

if( head == NULL){
       Node* temp = new Node(element);
       head = temp;
}

else {
    Node* curr = head;
    Node* prev= NULL;
    while ( curr -> data < element ){
           prev = curr;
           curr = curr -> next;

        }
        Node* temp = new Node (element );
        if( curr ==head){
             temp -> next = head;
             head = temp;

       }
       else {
           prev -> next = temp ;
           temp -> next = curr;
      }

   }

}


void deleteNode(int element, Node*& head) {
    if (head == NULL) {
        return;
    }

    if (head->data == element) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL && curr->data != element) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        prev->next = curr->next;
        delete curr;
    }
}


void printNode (Node* & head) {
      
     Node* curr = head;
     while( curr != NULL) {
           cout << curr-> data << " -> ";
           curr = curr-> next;
      }
    
}

int main (){

Node* head = NULL;
   insertNode(50,head);
   insertNode(30,head);
   insertNode(10,head);
   cout << "Node before deletion: ";
   printNode (head);

   deleteNode(30,head);
     cout << "\nNode after deletion: ";
     printNode (head);
}