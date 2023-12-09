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

int sizeofNode(Node* &head, Node* &tail){
     int count = 0;
     Node* curr = head;
     while(curr != NULL){
          count++;
          curr = curr->next;
     }
     return count;
}

void insertNode(int element, Node*& head, Node*& tail) {
    Node* temp = new Node(element);
    if (head == NULL) {
        head = tail = temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && curr->data < element) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) {
            temp->next = head;
            head = temp;
        } else if (curr == NULL) {
            tail->next = temp;
            tail = temp;
        } else {
            prev->next = temp;
            temp->next = curr;
        }
    }
}

void halfNode(int size,Node* &head, Node* &tail  ){
     int mid = size/2;
     Node* curr = head;
     int count = 0;
     while( count < mid){
          curr = curr->next;
          count++;
     }
     tail->next = head;
     Node* newHead = curr->next;
     head = newHead;
     curr->next=NULL;
     tail = curr;
}

void evenBeforeOdd(Node*& head, Node*& tail) {
     Node* end = tail;
     Node* prev = NULL;
     Node* curr = head;

     while (curr != end) {
          if (curr->data % 2 != 0) {
               tail->next = curr;
               curr = curr->next;
               if (prev != NULL) {
                    prev->next = curr;
               }
               tail = tail->next;
               tail->next = NULL;
          } else {
               if (prev == NULL) {
                    head = curr;
               }
               prev = curr;
               curr = curr->next;
          }
     }

     if (tail != end && end->data % 2 != 0) {
          tail->next = end;
          if (prev != NULL) {
               prev->next = end->next;
          }
          tail = tail->next;
          tail->next = NULL;
     }
}

void printNode (Node* & head) {
      
     Node* curr = head;
     while( curr != NULL) {
           cout << curr-> data << " -> ";
           curr = curr-> next;
      }
    
}

int main(){
     Node *head = NULL;
     Node *tail = NULL;
     insertNode(14,head,tail);
     insertNode(87,head,tail);
     insertNode(29,head,tail);
     insertNode(53,head,tail);
     insertNode(78,head,tail);
     cout<< "Original list : ";
     cout << endl;
     printNode(head);
     int size = sizeofNode(head,tail);
     halfNode(size, head, tail);
     cout << endl;
     cout<< "Shifting Halfnode :";
     cout << endl;
     printNode(head);
     cout<< "\nLinked list after moving even before odd : ";
     evenBeforeOdd(head, tail);
     cout << endl;
     printNode(head);
}