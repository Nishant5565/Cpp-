#include <iostream>
using namespace std;


//Note-  struct is used to create a user defined data type just like class. The only difference is that its default access type is public.

struct Node {
    int data;
    Node* next;
};



class CircularLinkedList {
private:
    Node* head;

public:


     // Note - A constructor is called automatically when an object is created. It is called constructor because it constructs the values of data members of the class. It is declared just like a function, but its name is the same as the class name. It does not have any return type, not even void. Constructors can be very useful for setting initial values for certain member variables.

    CircularLinkedList() : head(nullptr) {}   

     // ? CircularLinkedList(): This is the constructor declaration. It's a special member function that gets called when an object of the class is created. In this case, the constructor takes no parameters, indicating that it's a default constructor. The body of the constructor is empty, meaning it does nothing.
     // * Here head is initialized to nullptr. This is a null pointer, which is a pointer that does not point to any memory location. It's a good practice to initialize pointers to nullptr if they don't point to anything.
  



    void insert(int value);
    void display();
    void deleteNode(int value);
};

//!  Function to insert a new node at the end

void CircularLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

//! Function to display the circular linked list

void CircularLinkedList::display() {
    if (!head) {
        cout << "List is empty." <<   endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout <<   endl;
}

//! Function to delete a node by value

void CircularLinkedList::deleteNode(int value) {
    if (!head) {
        cout << "List is empty. Cannot delete." <<   endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    // Find the node to be deleted and the previous node
    while (current->next != head && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If the node is found, delete it
    if (current->data == value) {
        if (current == head) {
            Node* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }

            if (head == head->next) {
                delete head;
                head = nullptr;
            } else {
                lastNode->next = head->next;
                delete head;
                head = lastNode->next;
            }
        } else {
            previous->next = current->next;
            delete current;
        }
    } else {
          cout << "Node with value " << value << " not found." <<   endl;
    }

     cout << "List after deletion: ";
    display();
}

int main() {
    CircularLinkedList myList;

    // Inserting elements
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);

    // Displaying elements
      cout << "Original List: ";
    myList.display();

    myList.deleteNode(2);


    return 0;
}
