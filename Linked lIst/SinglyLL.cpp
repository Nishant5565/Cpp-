#include <iostream>
using namespace std;
class Node{
     public:
     int data;
     Node* nextadd;
     Node(int data){
          this->data = data;
          this->nextadd = NULL;
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

void print(Node* &head){

     Node*temp = head;
     while(temp!=NULL){
          cout<< temp->data <<" ";
          temp = temp->nextadd;
     }
     cout<<endl;

}

int main(){

     Node* node1= new Node(10);
     Node* head = node1;
     Node* tail = node1;
     insertAtHead(head, 20);
     insertAtTail(tail, 30);
     cout<<"Enter data \n";
     int data1 = 123;
     // cin>>data1;
     cout<<"Enter Position \n";
     int position = 2;
     // cin>>position;
     insertAtPosition(head, tail, position, data1);
     // cout<<tail->data<<endl;
     print(head);
     // cout<< head->data<< endl;
     // cout<<tail->data;
}