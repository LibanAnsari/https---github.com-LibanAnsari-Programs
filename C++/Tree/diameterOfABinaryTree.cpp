#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
    // Helper function to calculate height and diameter
    int hnd(Node *root, int &diameter) {
        if (root == nullptr) {
            return 0;  // height of an empty tree is 0
        }

        int lh = hnd(root->left, diameter);  // height of left subtree
        int rh = hnd(root->right, diameter); // height of right subtree

        // The diameter passing through this node
        int currDiameter = lh + rh + 1;

        // Update the global diameter if the current one is larger
        diameter = max(diameter, currDiameter);

        // Return the height of this subtree
        return max(lh, rh) + 1;
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int diameter = 0;  // Initialize diameter
        hnd(root, diameter);
        return diameter;  // No need to subtract 1, diameter is correctly computed
    }
};

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Create the binary tree from the example:
    // Input: 5 5 N 4 10 N 8 5 N 8 8 N 6
    Node* root = newNode(5);
    root->left = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(10);
    root->left->left->right = newNode(8);
    root->left->right->left = newNode(5);
    root->left->left->right->left = newNode(8);
    root->left->left->right->left->right = newNode(6);
    root->left->right->left->left = newNode(8);

    Solution sol;
    cout << "Diameter of the tree: " << sol.diameter(root) << endl;

    return 0;
}
