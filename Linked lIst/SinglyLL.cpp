// ! Menu Driven Program to implement a Singly Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nextadd;

    Node(int data) {
        this->data = data;
        this->nextadd = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->nextadd != NULL) {
            delete nextadd;
            this->nextadd = NULL;
            cout << "Memory is free for the node runned by condition with data  " << value << endl;
        }
        cout << "Memory is free for the node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->nextadd = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* newtail = new Node(data);
    tail->nextadd = newtail;
    tail = newtail;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    Node* temp = head;
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    if (temp->nextadd == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node* insertion = new Node(data);
    int count = 1;
    while (count < position - 1) {
        temp = temp->nextadd;
        count++;
    }
    insertion->nextadd = temp->nextadd;
    temp->nextadd = insertion;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    if (position == 1) {
        Node* temp = head;
        head = temp->nextadd;
        temp->nextadd = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while (count < position) {
            prev = curr;
            curr = curr->nextadd;
            count++;
        }
        if (curr->nextadd == NULL) {
            prev->nextadd = NULL;
            tail = prev;
            delete curr;
        } else {
            prev->nextadd = curr->nextadd;
            curr->nextadd = NULL;
            delete curr;
        }
    };
}

void deleteWholeAfterElement(Node* &head, Node* &tail, int data) {
    Node* curr = head;
    while (curr->data != data) {
        curr = curr->nextadd;
    }

    Node* temp = curr->nextadd;
    while (temp != NULL) {
        Node* p = temp;
        temp = temp->nextadd;
        p->nextadd = NULL;
        delete p;
    }

    if (tail->data == data) {
        return;
    }

    curr->nextadd = NULL;
    tail = curr;
}

void deleteWholeNode(Node* &head, Node* &tail) {
    Node* curr = head;
    while (curr != NULL) {
        Node* p = curr;
        curr = curr->nextadd;
        p->nextadd = NULL;
        delete p;
    }
    head = NULL;
    tail = NULL;
}

void deleteWholeFromCurrent(Node* &head, Node* &tail, int data) {
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while (curr->data != data) {
        prev = curr;
        curr = curr->nextadd;
    }
    if (curr == tail) {
        delete curr;
        prev->nextadd = NULL;
        return;
    }

    if (head->data == data) {
        deleteWholeNode(head, tail);
        return;
    }

    while (curr != NULL) {
        Node* p = curr;
        curr = curr->nextadd;
        p->nextadd = NULL;
        delete p;
    }
    prev->nextadd = NULL;
    tail = prev;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->nextadd;
    }
    cout << endl;
}

bool isEmpty(Node* head) {
     if(head == NULL){
            cout << "List is empty" << endl;
     }else{
            cout << "List is not empty Current list is: ";
               print(head);
     }
    return head == NULL;
}

int main() {
    Node* node1 = new Node(20);
    Node* head = node1;
    Node* tail = node1;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node\n";
        cout << "5. Delete Whole After Element\n";
        cout << "6. Delete Whole Node\n";
        cout << "7. Delete Whole From Current\n";
        cout << "8. Print List\n";
        cout << "9. Check if List is Empty\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                insertAtHead(head, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                insertAtTail(tail, data);
                break;
            }
            case 3: {
                int position, data;
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter data: ";
                cin >> data;
                insertAtPosition(head, tail, position, data);
                break;
            }
            case 4: {
                int position;
                cout << "Enter position to delete: ";
                cin >> position;
                deleteNode(head, tail, position);
                break;
            }
            case 5: {
                int data;
                cout << "Enter data after which to delete: ";
                cin >> data;
                deleteWholeAfterElement(head, tail, data);
                break;
            }
            case 6: {
                deleteWholeNode(head, tail);
                break;
            }
            case 7: {
                int data;
                cout << "Enter data to start deleting from: ";
                cin >> data;
                deleteWholeFromCurrent(head, tail, data);
                break;
            }
            case 8: {
                print(head);
                break;
            }
            case 9: {
                    isEmpty(head);
                break;
            }
            case 10: {
               cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 10);

    return 0;
}
