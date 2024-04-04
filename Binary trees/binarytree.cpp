#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the binary tree
Node* insert(Node* root, int value) {

    // Stop condition: if the root is null, create a new node

    
    // Base case: if the tree is empty, create a new node
    if (root == nullptr) {
        return new Node(value);
    }

    // Recursive cases: go to the left or right subtree based on the value
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // If the value already exists, do nothing
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
         cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to perform a pre-order traversal of the binary tree
void preorderTraversal(Node* root) {
    if (root != nullptr) {
         cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform a post-order traversal of the binary tree
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
         cout << root->data << " ";
    }
}

// Function to search for a value in the binary tree
bool search(Node* root, int value) {
    // Base cases: if the root is null or the value is found
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }

    // Recursive cases: search in the left or right subtree
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    // Create an empty binary tree
    Node* root = nullptr;

    // Insert values into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal
     cout << "In-order traversal: ";
    inorderTraversal(root);
     cout <<  endl;

    // Perform pre-order traversal
     cout << "Pre-order traversal: ";
    preorderTraversal(root);
     cout <<  endl;

    // Perform post-order traversal
     cout << "Post-order traversal: ";
    postorderTraversal(root);
     cout <<  endl;

    // Search for a value in the binary tree
    int searchValue = 40;
    if (search(root, searchValue)) {
         cout << searchValue << " found in the tree." <<  endl;
    } else {
         cout << searchValue << " not found in the tree." <<  endl;
    }

    // Deallocate memory (optional, as some systems may handle it automatically)
    // You may implement a destructor for more complex scenarios.
    // This is a simple example, and deallocation might not be necessary.
    // delete root;

    return 0;
}
