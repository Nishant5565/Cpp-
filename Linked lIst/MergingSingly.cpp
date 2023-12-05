#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

     // ! default constructor for the linked list class.
    LinkedList() : head(nullptr) {}

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
             cout << temp->data << " ";
            temp = temp->next;
        }
         cout <<  endl;
    }

    void mergeSortedLists(LinkedList& list1, LinkedList& list2) {
        Node* mergedHead = nullptr;
        Node* tail = nullptr;

        Node* current1 = list1.head;
        Node* current2 = list2.head;

        while (current1 && current2) {
            Node* newNode = nullptr;

            if (current1->data < current2->data) {
                newNode = new Node(current1->data);
                current1 = current1->next;
            } else {
                newNode = new Node(current2->data);
                current2 = current2->next;
            }

            if (!mergedHead) {
                mergedHead = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        while (current1) {
            Node* newNode = new Node(current1->data);
            tail->next = newNode;
            tail = newNode;
            current1 = current1->next;
        }

        while (current2) {
            Node* newNode = new Node(current2->data);
            tail->next = newNode;
            tail = newNode;
            current2 = current2->next;
        }

        head = mergedHead;
    }
};

int main() {
    LinkedList list1, list2, mergedList;

//? elements for the first sorted list

    list1.insertNode(1);
    list1.insertNode(3);
    list1.insertNode(5);

//? elements for the second sorted list
    list2.insertNode(2);
    list2.insertNode(4);
    list2.insertNode(6);

     cout << "List 1: ";
    list1.displayList();

     cout << "List 2: ";
    list2.displayList();

    mergedList.mergeSortedLists(list1, list2);

     cout << "Merged List: ";
    mergedList.displayList();

    return 0;
}
