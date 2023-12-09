#include <iostream>
using namespace std;


class Node{
     public:
     int data;
     Node* next;

     Node(int data){
          this->data= data;
          this->next = NULL;

     }
};


void insertatHead(Node* &head, int element){
     Node* temp = new Node(element);
     if(head == NULL){
          head = temp;
          return;
     }
     temp->next = head;
     head = temp;
}

void searchElement(Node* head, int element){
     Node* curr = head;
     int count = 0;
     while(curr != NULL){
          if(curr->data == element){
               cout << "Element found at index: " << count << endl;
               return;
          }
          count++;
          curr = curr->next;
     }
     cout << "Element not found" << endl;
}


void printList(Node* head){
     Node* curr = head;
     while(curr != NULL){
          cout << curr->data << " ";
          curr = curr->next;
     }
     cout << endl;
}
int main(){

     Node* head = NULL;
     insertatHead(head, 10);
     insertatHead(head, 20);
     insertatHead(head, 30);
     insertatHead(head, 40);
     insertatHead(head, 50);
     insertatHead(head, 60);
     printList(head);
     searchElement(head, 30);

}