#include <iostream>
using namespace std;

class Node{
     public:
     int data;
     Node* next;
     Node(int data){
          this->data= data;
          this->next=NULL;
     }
     
};

void insertAtHead(Node* &head, int data){

     Node* temp = new Node(data);
     temp->next = head;
     head = temp;
}

void insertAtTail(Node* &tail, int data){
     Node* temp = new Node(data);
     tail->next = temp;
     tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
     Node* temp = head;
     if(position == 1){
          insertAtHead(head,data);
          return;
     }
     if(temp->next == NULL){
          insertAtTail(tail,data);
          return;
     }
     Node* insertion = new Node(data);
     int count = 1;
     while(count < position-1){
          temp = temp->next;
          count++;
     }
     insertion->next = temp->next;
     temp->next = insertion;
}

void merging(Node* &head1, Node* &head2){
     Node* temp1 = head1;
     Node* temp2 = head2;
     Node* dummyNode = new Node(-1);
     Node* temp3 = dummyNode;
     while(temp1!=NULL && temp2!=NULL){
          if(temp1->data < temp2->data){
               temp3->next = temp1;
               temp1 = temp1->next;
          }
          else{
               temp3->next = temp2;
               temp2 = temp2->next;
          }
          temp3 = temp3->next;
     }
     while(temp1!=NULL){
          temp3->next = temp1;
          temp1 = temp1->next;
          temp3 = temp3->next;
     }
     while(temp2!=NULL){
          temp3->next = temp2;
          temp2 = temp2->next;
          temp3 = temp3->next;
     }
     head1 = dummyNode->next;
}

int main(){
     Node* node1 = new Node(10);
     Node* head1 = node1;
     Node* tail1 = node1;
     insertAtHead(head1, 0);
     insertAtTail(tail1, 20);
     insertAtTail(tail1, 30);
     
}