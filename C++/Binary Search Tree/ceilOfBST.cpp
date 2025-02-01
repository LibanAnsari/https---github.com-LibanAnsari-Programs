#include <iostream>
#include <climits> // for INT_MAX
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

// Function to find the ceiling of a given key in a BST
int findCeil(Node* root, int key) {
    if (root == NULL) return -1; // If the tree is empty, return -1 (no ceiling)

    int res = INT_MAX; // Initialize result to INT_MAX to find the minimum possible ceiling
    
    // Iterative traversal of the BST
    while (root != NULL) {
        
        if (root->data == key) {
            // If the current node's value matches the key, it is the ceiling
            res = root->data;
            return root->data;
        }
        
        if (root->data > key) {
            // If the current node's value is greater than the key, it could be a potential ceiling
            res = min(res, root->data);
            // Move to the left subtree to find a smaller possible ceiling
            root = root->left;
        } else {
            // If the current node's value is smaller than the key, move to the right subtree
            root = root->right;
        }
    }
    
    // If no valid ceiling is found (res remains INT_MAX), return -1
    if (res == INT_MAX) {
        return -1;
    }
    
    // Return the smallest value greater than or equal to the key
    return res;
}

// Helper function to print the ceiling value
void printCeil(Node *root, int key) {
    int result = findCeil(root, key);
    if (result == -1) {
        cout << "Ceiling of " << key << " doesn't exist in the tree." << endl;
    } else {
        cout << "Ceiling of " << key << " is: " << result << endl;
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

    // Test findCeil function with different keys
    printCeil(root, 6);   // Example where ceil exists (output: Ceiling of 6 is: 7)
    printCeil(root, 10);  // Example where key exists in the tree (output: Ceiling of 10 is: 10)
    printCeil(root, 20);  // Example where key is larger than any element (output: Ceiling of 20 doesn't exist)
    printCeil(root, 2);   // Example where key is smaller than all elements (output: Ceiling of 2 is: 3)

    return 0;
}
