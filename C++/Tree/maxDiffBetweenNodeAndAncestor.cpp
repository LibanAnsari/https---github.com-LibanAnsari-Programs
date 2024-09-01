#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function to calculate the maximum difference
    int findMaxDifference(Node *root, int &maxDifference) {
        if (root == NULL) {
            return INT_MAX; // Return INT_MAX since we are finding the minimum value
        }
        
        if (root->left == NULL && root->right == NULL) {
            return root->data; // If it's a leaf node, return its value as the min value
        }
        
        int lMin = findMaxDifference(root->left, maxDifference);
        int rMin = findMaxDifference(root->right, maxDifference);
        
        int subTreeMin = min(lMin, rMin); // Find the minimum value in the left and right subtrees
        
        maxDifference = max(maxDifference, root->data - subTreeMin); // Update maxDifference based on the current node
        
        return min(subTreeMin, root->data); // Return the minimum value including the current node
    }
    
    // Function to return the maximum difference between a node and its ancestor
    int maxDiff(Node* root) {
        int maxDifference = INT_MIN;
        findMaxDifference(root, maxDifference);
        return maxDifference;
    }
};

// Utility function to print the tree in a structured format (optional for debugging)
void printTree(Node* node, string indent = "", bool last = true) {
    if (node != NULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << node->data << endl;
        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}

int main() {
    Solution sol;

    // Creating the tree for the test case 1
    Node* root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    
    cout << "Tree 1:" << endl;
    printTree(root1); // Optional: Print the tree structure

    int result1 = sol.maxDiff(root1);
    cout << "Maximum difference for tree 1: " << result1 << endl; // Expected output: -1

    // Creating the tree for the test case 2
    Node* root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(1);
    
    cout << "\nTree 2:" << endl;
    printTree(root2); // Optional: Print the tree structure

    int result2 = sol.maxDiff(root2);
    cout << "Maximum difference for tree 2: " << result2 << endl; // Expected output: 4

    // Clean up the allocated memory
    delete root1->left;
    delete root1->right;
    delete root1;
    
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
