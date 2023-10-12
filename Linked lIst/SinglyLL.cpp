#include <iostream>
using namespace std;
class Node{
     public:
     int data;
     Node* nextadd;

     // Constructor
     Node(int data){
          this->data = data;
          this->nextadd = NULL;
     }
     // Destructor
     ~Node(){
          int value = this->data;
          if( this->nextadd!= NULL){
               delete nextadd;
               this->nextadd = NULL;
               cout<< "Memory is free for the node runned by condition with data  "<< value<<endl;

          }
          cout<< "Memory is free for the node with data "<< value<<endl;
     }
};



void insertAtHead(Node* &head,int data){
     Node* temp = new Node(data);
     temp->nextadd = head;
     head = temp;
}

void insertAtTail(Node* &tail, int data){

     Node* newtail= new Node(data);
     tail->nextadd = newtail;
     tail = newtail;

}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){


     Node* temp = head;
     if(position == 1){
          insertAtHead(head,data);
          return;
     }

     if(temp->nextadd == NULL){
          insertAtTail(tail, data);
          return;
     }

     Node* insertion = new Node(data);
     int count =1;
     while(count < position-1){
          temp = temp->nextadd;
          count++;
     }
     insertion->nextadd = temp->nextadd;
     temp->nextadd = insertion;

}

void deleteNode(Node* &head, Node* &tail, int position){
     if( position ==1){
          Node* temp = head;
          head = temp->nextadd;
          temp->nextadd = NULL;
          delete temp;
     }
     else {
          Node* curr = head;
          Node* prev = NULL;
          int count = 1;
          while(count < position){
               prev = curr;
               curr = curr->nextadd;
               count++;
          }
          if( curr->nextadd == NULL){
               prev->nextadd =NULL;
               tail = prev;
               delete curr;
          }
          else{
               prev->nextadd = curr->nextadd;
               curr->nextadd = NULL;
               delete curr;
          }
     };
}

void deleteWholeAfterElement(Node* &head, Node* &tail, int data){

     Node* curr = head;
     while ( curr->data != data){
          curr = curr->nextadd;
     }

     Node* temp = curr->nextadd;
     while(temp!=NULL){
          Node* p = temp;
          temp= temp->nextadd;
          p->nextadd = NULL;
          delete p;
     }

     if( tail->data == data){
          return;
     }

     curr->nextadd= NULL;
     tail = curr;


}
void deleteWholeNode(Node* &head, Node* &tail){
     Node* curr= head;
     while(curr!=NULL){

          Node* p = curr;
          curr= curr->nextadd;
          p->nextadd= NULL;
          delete p;

     }
     head = NULL;
     tail=NULL;
}


void deleteWholeFromCurrent(Node * &head, Node * &tail, int data){
     Node* curr = head;
     Node* prev= NULL;
     int count=0;
     while(curr->data!= data){
          prev = curr;
          curr = curr->nextadd;

     }
     if(curr == tail){
          // curr->nextadd=NULL;
          delete curr;
          prev->nextadd =NULL;
          return;
     }

     if(head->data==data){
          deleteWholeNode(head,tail);
          return;
     }

     while(curr!=NULL){
          Node* p = curr;
          curr = curr->nextadd;  
          p->nextadd=NULL;
          delete p;
     }
     prev->nextadd =NULL;
     tail = prev;
     

}




void print(Node* &head){

     Node*temp = head;
     while(temp!=NULL){
          cout<< temp->data <<" ";
          temp = temp->nextadd;
     }
     cout<<endl;

}

int main(){

     Node* node1= new Node(20);
     Node* head = node1;
     Node* tail = node1;
     insertAtHead(head, 10);
     insertAtTail(tail, 30);
     insertAtTail(tail, 40);



     // cout<<"Enter data \n";
     int data1 = 123;
     // cout<<"Enter Position \n";
     int position = 2;
     // insertAtPosition(head, tail, position, data1);
     // cout<<" Head is "<<head << endl;
     // cout<< " tail is "<<tail<< endl;
     print(head);
     // deleteNode(head, tail, 1 );
     // deleteWholeAfterElement(head,tail,20);
     // deleteWholeNode(head, tail);
     deleteWholeFromCurrent(head,tail,40);
     if( head == NULL || tail == NULL){
          cout<< "List is empty";
     }
     cout<<" Head is "<<head->data << endl;
     cout<< " tail is "<<tail->data<< endl;
     print(head);

}