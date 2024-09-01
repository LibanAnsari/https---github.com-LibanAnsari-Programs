#include <iostream>
#include <cmath>

using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to check if the binary tree is height-balanced
    bool isBalanced(Node* root) {
        // Call the recursive balance check function and see if it returns -1 (unbalanced)
        return isBalancedAndHeight(root) != -1;
    }

private:
    // Recursive function to check balance and calculate height
    int isBalancedAndHeight(Node* node) {
        // Base case: An empty tree is balanced with a height of 0
        if (node == NULL) {
            return 0;
        }

        // Recursively check the height of the left subtree
        int leftHeight = isBalancedAndHeight(node->left);
        if (leftHeight == -1) {
            return -1; // Left subtree is not balanced
        }

        // Recursively check the height of the right subtree
        int rightHeight = isBalancedAndHeight(node->right);
        if (rightHeight == -1) {
            return -1; // Right subtree is not balanced
        }

        // Check the balance condition for the current node
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is not balanced
        }

        // Return the height of the subtree
        return max(leftHeight, rightHeight) + 1;
    }
};

// Example usage
int main() {
    // Construct a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(3);

    Solution solution;
    if (solution.isBalanced(root)) {
        cout << "The tree is height balanced." << endl;
    } else {
        cout << "The tree is not height balanced." << endl;
    }

    // Another sample tree
    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);
    root2->left->left = new Node(40);
    root2->left->right = new Node(60);

    if (solution.isBalanced(root2)) {
        cout << "The tree is height balanced." << endl;
    } else {
        cout << "The tree is not height balanced." << endl;
    }

    return 0;
}
