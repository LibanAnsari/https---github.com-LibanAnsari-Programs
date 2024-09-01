#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the sum of subtrees and count the ones with sum X
int countSubtreesWithSumXUtil(Node* root, int X, int& count) {
    if (!root) return 0;

    // Calculate the sum of the left and right subtrees
    int leftSum = countSubtreesWithSumXUtil(root->left, X, count);
    int rightSum = countSubtreesWithSumXUtil(root->right, X, count);

    // Total sum of the current subtree
    int totalSum = root->data + leftSum + rightSum;

    // If the total sum is equal to X, increment the count
    if (totalSum == X) count++;

    return totalSum;
}

// Function to count the number of subtrees with sum X
int countSubtreesWithSumX(Node* root, int X) {
    int count = 0;
    countSubtreesWithSumXUtil(root, X, count);
    return count;
}

// Example usage
int main() {
    Node* root = new Node(5);
    root->left = new Node(-10);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    root->right->left = new Node(-4);
    root->right->right = new Node(7);

    int X = 7;
    cout << "Number of subtrees with sum " << X << ": " << countSubtreesWithSumX(root, X) << endl;

    return 0;
}
