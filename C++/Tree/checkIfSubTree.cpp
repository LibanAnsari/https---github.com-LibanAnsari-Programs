#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper function to check if two trees are identical
bool areIdentical(Node* T, Node* S) {
    // Both trees are empty, they are identical
    if (T == nullptr && S == nullptr) {
        return true;
    }
    
    // If one tree is empty and other is not, they are not identical
    if (T == nullptr || S == nullptr) {
        return false;
    }
    
    // Check if the data of both nodes are the same and recurse for their children
    return (T->data == S->data) &&
           areIdentical(T->left, S->left) &&
           areIdentical(T->right, S->right);
}

// Function to check if S is a subtree of T
bool isSubtree(Node* T, Node* S) {
    // Base cases
    if (S == nullptr) {
        return true;  // An empty tree is always a subtree
    }
    if (T == nullptr) {
        return false; // A non-empty tree cannot be a subtree of an empty tree
    }
    
    // If the current nodes of T and S are identical, check if S is a subtree rooted at this node
    if (areIdentical(T, S)) {
        return true;
    }
    
    // Recur for left and right subtrees of T
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}

// Function to create a sample binary tree for testing
Node* createSampleTreeT() {
    Node* root = new Node(26);
    root->left = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(30);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(60);
    return root;
}

Node* createSampleTreeS() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    return root;
}

int main() {
    Node* T = createSampleTreeT();
    Node* S = createSampleTreeS();
    
    if (isSubtree(T, S)) {
        cout << "S is a subtree of T" << endl;
    } else {
        cout << "S is NOT a subtree of T" << endl;
    }
    
    return 0;
}
