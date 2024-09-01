#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(Node* n1, Node* n2) {
    // Both are NULL
    if (n1 == NULL && n2 == NULL) {
        return true;
    }
    
    // One is NULL and the other is not
    if (n1 == NULL || n2 == NULL) {
        return false;
    }
    
    // Both are non-NULL, check if left of n1 and right of n2 are mirrors
    // and right of n1 and left of n2 are mirrors
    return (isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left));
}

// Main function to check if the tree is foldable
bool isFoldable(Node* root) {
    if (root == NULL) {
        return true; // An empty tree is foldable
    }
    
    return isMirror(root->left, root->right);
}

// Utility function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    node->left = node->right = NULL;
    return node;
}

int main() {
    /* Let's create the following binary tree as an example
              10
            /    \
           7      15
            \    /
             9  11
    */
    Node* root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(15);
    root->left->right = newNode(9);
    root->right->left = newNode(11);

    if (isFoldable(root)) {
        cout << "Yes, the tree is foldable." << endl;
    } else {
        cout << "No, the tree is not foldable." << endl;
    }
    
    return 0;
}
