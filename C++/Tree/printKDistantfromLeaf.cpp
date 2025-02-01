#include <iostream>
using namespace std;

#define MAX_HEIGHT 1000

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Utility function to count nodes at a given distance from leaf nodes.
void kDistantFromLeafUtil(Node* node, int &count, bool visited[], int pathLen, int k) {
    // Base case
    if (node == NULL) return;

    visited[pathLen] = false;
    pathLen++;

    // If it's a leaf node, increment the count but only if the 
    // same ancestor at distance k is not already counted.
    if (node->left == NULL && node->right == NULL &&
        pathLen - k - 1 >= 0 && visited[pathLen - k - 1] == false) {
        count++;
        // Mark the ancestor as visited so that we won't count it again.
        visited[pathLen - k - 1] = true;
        return;
    }

    // Recursively call the function for left and right subtrees.
    kDistantFromLeafUtil(node->left, count, visited, pathLen, k);
    kDistantFromLeafUtil(node->right, count, visited, pathLen, k);
}

// Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* node, int k) {
    int count = 0;
    bool visited[MAX_HEIGHT] = {false}; // Array to mark visited ancestors
    kDistantFromLeafUtil(node, count, visited, 0, k);
    return count; // Return the count of nodes at distance k from leaf nodes
}

// Main function to test the utility function.
int main(){
    // Creating a sample binary tree
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //           \
    //            8

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    int k = 2;
    cout << "Number of nodes at distance " << k << " from a leaf node: " 
         << printKDistantfromLeaf(root, k) << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
