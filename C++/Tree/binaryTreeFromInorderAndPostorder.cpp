#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inorderMap;

    // Helper function to build the binary tree
    Node* buildHelper(int inStart, int inEnd, int &postIndex, int in[], int post[]) {
        if (inStart > inEnd) {
            return NULL;
        }

        // The current root value is the last element in the current postorder segment
        int rootVal = post[postIndex];
        Node *root = new Node(rootVal);
        postIndex--;

        // Find the index of the root in inorder traversal
        int inIndex = inorderMap[rootVal];

        // Recursively build the right and left subtrees
        root->right = buildHelper(inIndex + 1, inEnd, postIndex, in, post);
        root->left = buildHelper(inStart, inIndex - 1, postIndex, in, post);

        return root;
    }

    // Main function to build the tree from inorder and postorder traversals
    Node* buildTree(int n, int in[], int post[]) {
        // Map each value to its index in the inorder traversal for quick lookup
        for (int i = 0; i < n; i++) {
            inorderMap[in[i]] = i;
        }
        
        int postIndex = n - 1;  // Start from the last element in postorder traversal
        return buildHelper(0, n - 1, postIndex, in, post);
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(Node* node) {
    if (node == NULL)
        return;

    // Traverse the left subtree
    printInorder(node->left);

    // Print the node data
    cout << node->data << " ";

    // Traverse the right subtree
    printInorder(node->right);
}

// Main function to test the buildTree function
int main() {
    /* Example:
       Inorder traversal:   {9, 3, 15, 20, 7}
       Postorder traversal: {9, 15, 7, 20, 3}
    */

    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Solution solution;
    Node* root = solution.buildTree(n, inorder, postorder);

    // Print the inorder traversal of the constructed tree to verify correctness
    cout << "Inorder traversal of the constructed tree:" << endl;
    printInorder(root);

    return 0;
}
