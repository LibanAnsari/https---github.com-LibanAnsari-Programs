#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Helper function to compute the maximum sum of non-adjacent nodes.
pair<int, int> solve(Node *root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;
    res.first = root->data + left.second + right.second; // Including current node
    res.second = max(left.first, left.second) + max(right.first, right.second); // Excluding current node

    return res;
}

// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

// Main function to test the getMaxSum function.
int main() {
/*
    Creating a sample binary tree
            1
          /   \
         2     3
        /     /  \
       4     5    6
*/             
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Maximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
