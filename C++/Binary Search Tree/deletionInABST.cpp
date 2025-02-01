#include <iostream>
using namespace std;

// Definition for a Binary Tree Node
struct Node {
    int data;         // Stores the data of the node
    Node *left, *right; // Pointers to the left and right children

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to find the node with the minimum value in the right subtree
Node *minValueNode(Node* node) {
    node = node->right;  // Move to the right subtree
    while (node->left != NULL) {
        node = node->left;  // Find the leftmost node, which is the smallest
    }
    return node;  // Return the node with the minimum value
}

// Function to delete a node with a given value 'x' from the BST
Node *deleteNode(Node *root, int x) {
    if (root == NULL) {
        return root;  // If the root is NULL, return (node not found)
    }

    // Traverse to the left subtree if 'x' is smaller than the current node's data
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } 
    // Traverse to the right subtree if 'x' is larger than the current node's data
    else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } 
    // If we find the node with value 'x'
    else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            Node *rightChild = root->right;  // Get the right child
            delete root;  // Delete the current node
            return rightChild;  // Return the right child to connect with parent
        } 
        else if (root->right == NULL) {
            Node *leftChild = root->left;  // Get the left child
            delete root;  // Delete the current node
            return leftChild;  // Return the left child to connect with parent
        }

        // Case 2: Node with two children
        // Find the inorder successor (smallest in the right subtree)
        Node *successor = minValueNode(root);  
        
        // Replace the current node's data with the successor's data
        root->data = successor->data;

        // Delete the inorder successor from the right subtree
        root->right = deleteNode(root->right, successor->data);
    }
    
    return root;  // Return the updated root of the BST
}

// Function to insert a new node with the given value into the BST
Node* insert(Node* node, int data) {
    if (node == NULL) return new Node(data);  // Create a new node if we reach a NULL position

    if (data < node->data)
        node->left = insert(node->left, data);  // Insert in the left subtree if the value is smaller
    else if (data > node->data)
        node->right = insert(node->right, data);  // Insert in the right subtree if the value is larger

    return node;  // Return the node (with updated left or right subtree)
}

// Function to print the inorder traversal of the tree (left -> root -> right)
void inorder(Node* root) {
    if (root == NULL) return;  // Base case: if the node is NULL, return

    inorder(root->left);  // Visit the left subtree
    cout << root->data << " ";  // Print the current node's data
    inorder(root->right);  // Visit the right subtree
}

int main() {
    Node* root = NULL;  // Initialize an empty BST

    // Insert nodes into the BST
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 12);

    // Print the inorder traversal of the original tree
    cout << "Inorder traversal of the original tree: ";
    inorder(root);
    cout << endl;

    // Delete node with value 9
    root = deleteNode(root, 9);

    // Print the inorder traversal after deleting the node with value 9
    cout << "Inorder traversal after deleting 9: ";
    inorder(root);
    cout << endl;

    return 0;
}
