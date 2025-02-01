#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left, *right;
    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Helper function to perform the in-order traversal and conversion to CDLL
void bCLL(Node *root, Node *&head, Node *&prev) {
    if (root == NULL) {
        return;
    }
    
    // Recursively convert the left subtree
    bCLL(root->left, head, prev);

    // If head is NULL, this is the first node (smallest element)
    if (head == NULL) {
        head = prev = root;
    } else {
        // Link the current node to the previous one
        prev->right = root;
        root->left = prev;
    }
    
    // Move prev pointer to the current node
    prev = root;

    // Recursively convert the right subtree
    bCLL(root->right, head, prev);
}

// Function to convert binary tree to circular doubly linked list
Node* bTreeToCList(Node *root) {
    if (root == NULL) return NULL;
    
    Node *head = NULL, *prev = NULL;
    
    // Convert the binary tree to a doubly linked list using in-order traversal
    bCLL(root, head, prev);
    
    // Make the doubly linked list circular
    prev->right = head;
    head->left = prev;
    
    return head;
}

// Helper function to print the circular doubly linked list
void printCList(Node *head) {
    if (head == NULL) return;
    
    Node *temp = head;
    
    // Print nodes in the list until we circle back to the head
    do {
        cout << temp->data << " ";
        temp = temp->right;
    } while (temp != head);
    
    cout << endl;
}

int main() {
    // Create a binary tree
    /*
            10
           /  \
          12   15
         / \   /
        25 30 36
    */
    
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
    
    // Convert the binary tree to a circular doubly linked list
    Node *head = bTreeToCList(root);
    
    // Print the circular doubly linked list
    cout << "Circular Doubly Linked List: ";
    printCList(head);
    
    return 0;
}
