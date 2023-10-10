#include <iostream>
using namespace std;
class node
{
public:
    int info;
    node *next;
};
class Llist
{
    node *head;

public:
    Llist()
    {
        head = NULL;
    }
    void isempty();
    void display();
    void insertathead(int item);
    void insertattail(int item);
    void insertafterelement(int item, int afterelement);
    void deletefromhead();
    void deletefromtail();
    void deleteElement(int item);
    void deleteAfterElement(int afterelement);
    void searching(int item);
};

void Llist::isempty()
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        cout << "Linked list is not empty" << endl;
    }
    cout << endl;
}
void Llist::insertathead(int item)
{
    cout << "Inserting at beginning: ";
    node *n1 = new node();
    n1->info = item;
    if (head == NULL)
    {
        n1->next = NULL;
    }
    else
    {
        n1->next = head;
    }
    head = n1;
    cout << endl;
}
void Llist::display()
{
    cout << "Linked list: ";
    node *p = head;
    while (p != NULL)
    {
        cout << p->info << " ->";
        p = p->next;
    }
    cout << endl;
}
void Llist::insertattail(int item)
{
    cout << "Inserting " << item << " at tail: ";
    node *ptr;
    node *n2 = new node();
    n2->info = item;
    n2->next = NULL;
    ptr = head;
    if (head == NULL)
    {
        head = n2;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n2;
    }
    cout << endl;
}
void Llist::insertafterelement(int item, int afterelement)
{
    cout << "Inserting " << item << " after " << afterelement << endl;
    node *ptr, *q;
    node *n3 = new node();
    n3->info = item;
    n3->next = NULL;
    ptr = head;
    if (head == NULL)
    {
        cout << "LINKED LIST does not exist." << endl;
    }
    else
    {
        while (ptr->info != afterelement)
        {
            if (ptr->next == NULL)
            {
                cout << "Element not found" << endl;
            }
            ptr = ptr->next;
        }
        q = ptr->next;
        ptr->next = n3;
        n3->next = q;
    }
    cout << endl;
}
void Llist::deletefromhead()
{
    cout << "Deleting head node: " << endl;
    node *p;
    if (head == NULL)
    {
        cout << "LINKED LIST does not exist" << endl;
    }
    else if (head->next == NULL)
    {
        p = head;
        head = NULL;
        delete p;
    }
    else
    {
        p = head;
        head = head->next;
        delete p;
    }
}
void Llist::deletefromtail()
{
    cout << "Deleting tail node: " << endl;
    node *p;
    if (head == NULL)
    {
        cout << "Linked list does not exist" << endl;
    }
    else if (head->next == NULL)
    {
        p = head;
        head = NULL;
        delete p;
    }
    else
    {
        p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        delete p->next;
        p->next = NULL;
    }
}
void Llist::deleteElement(int item)
{
    cout << "Deleting element: " << endl;
    node *p, *q;
    p = head;
    if (head == NULL)
    {
        cout << "Linked list does not exist" << endl;
    }
    else if (head->next == NULL)
    {
        if (p->info == item)
        {
            head = NULL;
            delete p;
        }
    }
    else
    {
        if (p->info == item)
        {
            head = p->next;
            delete p;
        }
        else
        {
            while (p->next->info != item)
            {
                p = p->next;
            }
            q = p->next->next;
            delete p->next;
            p->next = q;
        }
    }
    //     cout<<"number does not exist";
}
void Llist::deleteAfterElement(int afterelement)
{
    node *p, *q;
    p = head;
    if (head == NULL)
    {
        cout << "linked list does not exist" << endl;
    }
    else
    {
        while (p->info != afterelement)
        {
            p = p->next;
        }
        q = p->next;
        p->next = p->next->next;
        delete q;
    }
}
void Llist::searching(int item)
{
    node *p;
    p = head;
    if (head == NULL)
    {
        cout << "Linked link does not exist" << endl;
    }
    else
    {
        while (p->info != item)
        {
            if (p->next == NULL)
            {
                cout << "Element not found" << endl;
            }
            p = p->next;
        }
        cout << "Element found" << endl;
    }
}

int main()
{
    Llist l1;
    cout << "WELCOME TO LINKED LIST" << endl;
    int choice;
    cout << "Do you want to continue in linked list(YES/NO): ";
    string status;
    cin >> status;
    while (status == "yes")
    {
        cout << "You are seeing for what??" << endl
             << "1.isEmpty CHECK" << endl
             << "2.DISPLAY" << endl
             << "3.INSERTION" << endl
             << "4.DELETION" << endl
             << "5.SEARCHING" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            l1.isempty();
        }
        else if (choice == 2)
        {
            l1.display();
        }
        else if (choice == 3)
        {
            cout << "Do you want to continue in insertion(yes/no): ";
            cin >> status;
            while (status == "yes")
            {
                cout << "1.INSERTING AT HEAD" << endl
                     << "2.INSERTING AT TAIL" << endl
                     << "3.INSERTING AFTER ELEMENT" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Enter number you want to insert: ";
                    int item;
                    cin >> item;
                    l1.insertathead(item);
                    l1.display();
                }
                else if (choice == 2)
                {
                    cout << "Enter number you want to insert: ";
                    int item;
                    cin >> item;
                    l1.insertattail(item);
                    l1.display();
                }
                else if (choice == 3)
                {
                    cout << "Enter number you want to insert: ";
                    int item;
                    cin >> item;
                    cout << "Enter number after which you want to insert element: ";
                    int afterelement;
                    cin >> afterelement;
                    l1.insertafterelement(item, afterelement);
                    l1.display();
                }
                else
                {
                    cout << "Wrong choice for insertion." << endl;
                }
                cout << "Do you want to continue in insertion: ";
                cin >> status;
            }
        }
        else if (choice == 4)
        {
            cout << "continue in deletion(yes/no): ";
            cin >> status;
            while (status == "yes")
            {
                cout << "1.DELETING FROM HEAD" << endl
                     << "2.DELETING FROM TAIL" << endl
                     << "3.DELETE ELEMENT" << endl
                     << "4.DELETING AFTER ELEMENT" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    l1.deletefromhead();
                    l1.display();
                }
                else if (choice == 2)
                {
                    l1.deletefromtail();
                    l1.display();
                }
                else if (choice == 3)
                {
                    cout << "Enter element: ";
                    int element;
                    cin >> element;
                    l1.deleteElement(element);
                    l1.display();
                }
                else if (choice == 4)
                {
                    cout << "Enter element after which you want to delete: ";
                    int element;
                    cin >> element;
                    l1.deleteAfterElement(element);
                    l1.display();
                }
                else
                {
                    cout << "Wrong choice for deletion" << endl;
                }
                cout << "Do you want to continue in deletion: ";
                cin >> status;
            }
        }
        else if (choice == 5)
        {
            cout << "Enter element for searching: ";
            int element;
            cin >> element;
            l1.searching(element);
        }
        else
        {
            cout << "Wrong choice for action" << endl;
        }
        cout << "Do you want to continue in linked list (YES/NO): ";
        cin >> status;
    }
    return 0;
}