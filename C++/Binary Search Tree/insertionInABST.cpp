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

// Class Solution contains the insert function for BST
class Solution
{
    public:
        // Function to insert a new node with given data into the BST
        Node* insert(Node* root, int data) {
            if (root == NULL) {
                return new Node(data); // Create a new node if the current position is NULL
            } else if (data < root->data) {
                root->left = insert(root->left, data); // Insert in the left subtree if data is smaller
            } else if (data > root->data) {
                root->right = insert(root->right, data); // Insert in the right subtree if data is larger
            }
            return root; // Return the root after insertion
        }
};

// Function to print the inorder traversal of the tree (left -> root -> right)
void inorder(Node* root) {
    if (root == NULL) return;  // Base case: if node is NULL, return
    inorder(root->left);       // Recursively visit the left subtree
    cout << root->data << " "; // Print the current node's data
    inorder(root->right);      // Recursively visit the right subtree
}

int main() {
    Solution sol;  // Create an object of the Solution class
    Node* root = NULL;  // Initialize the BST as an empty tree (root is NULL)

    // Insert nodes into the BST
    root = sol.insert(root, 10);
    root = sol.insert(root, 5);
    root = sol.insert(root, 20);
    root = sol.insert(root, 3);
    root = sol.insert(root, 7);
    root = sol.insert(root, 15);
    root = sol.insert(root, 30);

    // Print the inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
