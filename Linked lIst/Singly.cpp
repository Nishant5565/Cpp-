#include <iostream>
using namespace std;

// ? So first of all we created a class name as Node, so that we can create our linked lists with the datatype node. In this class we have passed some attributes like data and address of next linked list. 
class Node{
     public:
     int data;
     Node* next;
     // ? After then we initialised a parameterised constructor where we will pass the data of our Nodes. Everytime we create a new node the address will point to null, so we have to configure the address according to our functions. 
     Node(int data){
          this->data= data;
          this->next=NULL;
     }
     
};


// ? Insert at head means we are inserting our new node at head(in the starting).
// * Logic - So first of all we passed two parameters while calling the function then we recieve the parameters as arguements. After then we created a new node with name temp, now the Node have some data and is pointing NULL as the address but now we have to configure the adrress so that it points the head that is created previously. To be more specific we need to attach this list to the head that we have created in the starting. 

void insertAtHead(Node* &head, int data){  //? We use & because we want changes in the original head( node 1), and not in a copy.

     Node* temp = new Node(data);
     temp->next = head;
     head = temp;   //? Now head will contain the address value of temp.
}

void insertAttail(Node* &tail, int data){
     Node* temp = new Node(data);
     tail->next = temp;  //? First of all we Created a new node, then we want that our previous node should point towards the new node, so tail(node1) -> next = temp( the address of new node.)  
     tail = temp;
}
void insertAtPosition(Node* &tail ,Node* &head,int position, int data){
     // ?Inserting at head position 

     if(position == 1){
          insertAtHead(head,data);
          return;
     }

     Node* temp = head;
     int count = 1;
     while(count < position-1){
          temp = temp->next;
          count++;
     }

     // ? Inserting at last position

     if(temp->next == NULL){
          insertAttail(tail,data);
          return;
     }


     Node* nodeToInsert = new Node(data);
     nodeToInsert->next= temp->next;
     temp->next = nodeToInsert;

}

void deleteAtHead(Node* &head){
     Node* todelete = head;
     head = head->next;
     delete todelete;
}

void print(Node* &head){ 
     Node* tempadd= head;
     while(tempadd!=NULL){
          cout<< tempadd->data<<" ";
          tempadd = tempadd->next;
     }
     cout<<endl;
}


int main(){

     Node* node1 = new Node(10);
     Node* head = node1;
     Node* tail = node1;
     insertAtHead(head, 0);
     // print(head);
     insertAttail(tail, 30);
     insertAttail(tail, 40);
     print(head);
     insertAtPosition(tail,head,4,20);
     print(head);


     cout<<"head"<< head->data<<endl;
     cout<<"tail"<< tail->data<<endl;




}