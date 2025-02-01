#include <bits/stdc++.h>
using namespace std;

// Definition for a binary search tree (BST) node
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Recursive utility function to find the floor of a given key in a BST
void floorutil(Node *root, int key, int &res) {
    if (root == NULL) {
        return; // Base case: If the root is null, return
    }
    
    // If the current node's data matches the key, the key itself is the floor
    if (root->data == key) {
        res = root->data;
    }
    // If the current node's data is less than the key, update the floor value
    else if (root->data < key && res != key) {
        res = max(res, root->data);
    }
    
    // Recursively check the left or right subtree depending on the current node's value
    if (root->data > key) {
        floorutil(root->left, key, res); // Move left for smaller values
    } else {
        floorutil(root->right, key, res); // Move right for larger values
    }
}

// Function to find the floor of a given key in the BST
int floor(Node* root, int key) {
    if (root == NULL) {
        return -1; // If the tree is empty, return -1 (no floor exists)
    }
    int res = -1; // Initialize result to -1, meaning no floor has been found yet
    floorutil(root, key, res); // Call the helper function
    return res; // Return the final result
}

// Helper function to print the floor value
void printFloor(Node *root, int key) {
    int result = floor(root, key);
    if (result == -1) {
        cout << "Floor of " << key << " doesn't exist in the tree." << endl;
    } else {
        cout << "Floor of " << key << " is: " << result << endl;
    }
}

int main() {
    /*
        Creating the following binary search tree (BST):
                  10
                 /  \
               5     15
              / \    / \
             3   7  12  17
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);

    // Test floor function with different keys
    printFloor(root, 6);   // Example where floor exists (output: Floor of 6 is: 5)
    printFloor(root, 10);  // Example where key exists in the tree (output: Floor of 10 is: 10)
    printFloor(root, 20);  // Example where key is larger than any element (output: Floor of 20 is: 17)
    printFloor(root, 1);   // Example where key is smaller than any element (output: Floor of 1 doesn't exist)

    return 0;
}
