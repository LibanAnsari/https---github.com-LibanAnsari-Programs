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

// Function to convert a binary tree into its mirror
void mirror(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    // Recursively convert the left and right subtrees
    mirror(node->left);
    mirror(node->right);
    
    // Swap the left and right children
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

// Helper function for in-order traversal to print the tree nodes
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to create a sample binary tree for testing
Node* createSampleTree() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    return root;
}

int main() {
    Node* root = createSampleTree();
    
    cout << "In-order traversal before mirror: ";
    inorder(root);
    cout << endl;
    
    // Convert the tree to its mirror
    mirror(root);
    
    cout << "In-order traversal after mirror: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
