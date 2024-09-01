#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to convert a binary tree to a doubly linked list
    void treeToDLL(Node *root, Node *&head, Node *&prev) {
        if (root == NULL) return;

        // Recursively convert the left subtree
        treeToDLL(root->left, head, prev);

        // Process the current node
        if (prev == NULL) {
            // If prev is NULL, this is the leftmost node, set it as the head of DLL
            head = root;
        } else {
            // Link the previous node (prev) with the current node (root)
            root->left = prev;
            prev->right = root;
        }

        // Update prev to the current node
        prev = root;

        // Recursively convert the right subtree
        treeToDLL(root->right, head, prev);
    }

    // Function to initiate the conversion from binary tree to DLL
    Node* bToDLL(Node* root) {
        Node *head = NULL;  // Head of the DLL
        Node *prev = NULL;  // Pointer to keep track of the previous node

        // Convert the binary tree to DLL
        treeToDLL(root, head, prev);

        return head;  // Return the head of the created DLL
    }
};

// Helper function to print the DLL
void printDLL(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

// Helper function to create a binary tree node
Node* createNode(int data) {
    return new Node(data);
}

// Main function to test the conversion
int main() {
    /* Example Binary Tree
             10
           /    \
          5      20
         / \    /  \
        3   7  15   25
    */

    // Creating the binary tree
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // Convert the binary tree to DLL
    Solution solution;
    Node* head = solution.bToDLL(root);

    // Print the DLL
    cout << "Doubly Linked List from Binary Tree:" << endl;
    printDLL(head);

    return 0;
}
