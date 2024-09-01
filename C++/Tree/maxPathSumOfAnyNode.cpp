#include <iostream>
#include <algorithm>
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
    // Helper function to find the maximum path sum
    int findMaxPathSum(Node* root, int& globalMax) {
        if (root == NULL) {
            return 0;
        }
        
        // Recurse for left and right subtrees
        int leftSum = max(0, findMaxPathSum(root->left, globalMax));
        int rightSum = max(0, findMaxPathSum(root->right, globalMax));
        
        // Calculate the maximum path sum that passes through this node
        int localMax = root->data + leftSum + rightSum;
        
        // Update the global maximum if the local maximum is greater
        globalMax = max(globalMax, localMax);
        
        // Return the maximum sum starting from this node and extending to either side
        return root->data + max(leftSum, rightSum);
    }
    
    int findMaxSum(Node* root) {
        int globalMax = INT_MIN;  // Initialize the global maximum with the smallest possible integer
        findMaxPathSum(root, globalMax);  // Call the helper function to update globalMax
        return globalMax;  // Return the global maximum path sum
    }
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    node->left = node->right = NULL;
    return node;
}

int main() {
    Solution sol;
    
    /* Construct the following binary tree
              10
             /  \
            2   -25
           / \   /  \
          20  1  3  4
    */
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(-25);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->left = newNode(3);
    root->right->right = newNode(4);

    cout << "Maximum path sum: " << sol.findMaxSum(root) << endl;  // Output: 32
    
    return 0;
}
