#include <iostream>
using namespace std;



class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
    }
    void is_empty();
    void insert_at_head(int val);
    void insert_at_tail(int val);
    void insert_at_index(int val, int index);
    void insert_after_node(int val, int node_val);
    void delete_at_head();
    void delete_at_tail();
    void delete_at_index(int index);
    void delete_after_node(int node_val);
    void display();
    void search(int val);
};
void Node::is_empty(){
    if(this->next == NULL){
        cout<<"Linked List is empty"<<endl;
    }
    else{
        cout<<"Linked List is not empty"<<endl;
    }
}
void Node::insert_at_head(int val){
    Node* new_node = new Node(val);
    new_node->next = this->next;
    this->next = new_node;
    new_node->prev = this;
}
void Node::insert_at_tail(int val){
    Node* new_node = new Node(val);
    Node* temp = this;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
void Node::insert_at_index(int val, int index){
    Node* new_node = new Node(val);
    Node* temp = this;
    int i = 0;
    while(i < index-1){
        temp = temp->next;
        i++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}
void Node::insert_after_node(int val, int node_val){
    Node* new_node = new Node(val);
    Node* temp = this;
    while(temp->data != node_val){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}
void Node::delete_at_head(){
    Node* temp = this->next;
    this->next = temp->next;
    temp->next->prev = this;
    delete temp;
}
void Node::delete_at_tail(){
    Node* temp = this;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* to_delete = temp->next;
    temp->next = NULL;
    delete to_delete;
}
void Node::delete_at_index(int index){
    Node* temp = this;
    int i = 0;
    while(i < index-1){
        temp = temp->next;
        i++;
    }
    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    to_delete->next->prev = temp;
    delete to_delete;
}
void Node::delete_after_node(int node_val){
    Node* temp = this;
    while(temp->data != node_val){
        temp = temp->next;
    }
    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    to_delete->next->prev = temp;
    delete to_delete;
}
void Node::display(){
    Node* temp = this->next;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void Node::search(int val){
    Node* temp = this->next;
    while(temp != NULL){
        if(temp->data == val){
            cout<<"Found"<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Not Found"<<endl;
}
