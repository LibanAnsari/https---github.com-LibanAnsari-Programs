#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    // Constructor to initialize a node with given data
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to check whether all nodes of a tree have the value equal to the sum of their child nodes
    int isSumProperty(Node *root) {
        // Base case: If the node is NULL, it satisfies the sum property
        if (root == NULL) {
            return 1;
        }
        
        // Base case: If the node is a leaf node, it also satisfies the sum property
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        int leftData = 0, rightData = 0;
        
        // If the left child is not NULL, assign its data to leftData
        if (root->left != NULL) {
            leftData = root->left->data;
        }
        
        // If the right child is not NULL, assign its data to rightData
        if (root->right != NULL) {
            rightData = root->right->data;
        }
        
        // Check if the current node satisfies the sum property and recursively check for left and right subtrees
        if ((root->data == leftData + rightData) && 
            isSumProperty(root->left) && 
            isSumProperty(root->right)) {
            return 1;
        } else {
            return 0;
        }
    }
};

// Example usage
int main() {
    // Create a sample tree
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(6);
    
    Solution solution;
    if (solution.isSumProperty(root)) {
        cout << "The tree satisfies the sum property." << endl;
    } else {
        cout << "The tree does not satisfy the sum property." << endl;
    }
    
    return 0;
}
