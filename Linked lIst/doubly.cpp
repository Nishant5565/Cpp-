// ! Menu Driven Program to implement Doubly Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node() {
        int value = this->data;
        cout << "Destructor called for data " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;
    } else {
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data) {
    if (tail == NULL) {
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;
    } else {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtMiddle(Node* &head, Node* &tail, int data, int position) {
    Node* temp = new Node(data);
    Node* curr = head;
    int count = 1;

    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    } else if (position > getLength(head)) {
        cout << "Invalid Position... Aborting Program\n";
        return;
    } else {
        while (count < position - 1) {
            curr = curr->next;
            count++;
        }
        if (curr == tail) {
            insertAtTail(tail, head, data);
            return;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
}

void deleteNode(Node* &head, Node* &tail, int data) {
    Node* curr = head;
    Node* temp = NULL;

    if (head->data == data) {
        head = curr->next;
        curr->next->prev = NULL;
        curr->next = NULL;
        delete curr;
        return;
    }

    while (curr->data != data) {
        temp = curr;
        curr = curr->next;
    }

    if (curr == tail) {
        temp->next = NULL;
        tail = temp;
        curr->prev = NULL;
        delete curr;
        return;
    }

    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

void deleteWholeNode(Node* &head, Node* &tail) {
    Node* curr = head;
    while (curr != NULL) {
        Node* p = curr;
        curr = curr->next;
        p->next = NULL;
        p->prev = NULL;
        delete p;
    }
    head = NULL;
    tail = NULL;
}

void deleteAfterElement(Node* &head, Node* &tail, int data) {
    Node* curr = head;
    Node* temp = curr->next;

    while (curr->data != data) {
        temp = curr->next;
        curr = curr->next;
    }

    while (temp != NULL) {
        Node* p = temp;
        temp = temp->next;
        p->prev = NULL;
        p->next = NULL;
        delete p;
    }
    curr->next = NULL;
    tail = curr;
}

void print(Node* head) {
     if(head == NULL) {
        cout << "List is empty!\n";
        return;
     }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Middle\n";
        cout << "4. Delete Node\n";
        cout << "5. Delete Whole Node\n";
        cout << "6. Delete After Element\n";
        cout << "7. Print List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                insertAtHead(head, tail, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                insertAtTail(tail, head, data);
                break;
            }
            case 3: {
                int position, data;
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter data: ";
                cin >> data;
                insertAtMiddle(head, tail, data, position);
                break;
            }
            case 4: {
                int data;
                cout << "Enter data to delete: ";
                cin >> data;
                deleteNode(head, tail, data);
                break;
            }
            case 5: {
                deleteWholeNode(head, tail);
                break;
            }
            case 6: {
                int data;
                cout << "Enter data after which to delete: ";
                cin >> data;
                deleteAfterElement(head, tail, data);
                break;
            }
            case 7: {
                print(head);
                break;
            }
            case 8: {
                // Exit
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 8);

    return 0;
}
