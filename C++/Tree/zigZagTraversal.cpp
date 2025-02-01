#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to perform zigzag traversal
vector<int> zigZagTraversal(Node* root) {
    if (root == NULL) return {};

    vector<int> result;
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty()) {
        Node* temp = currLevel.top();
        currLevel.pop();

        if (temp != NULL) {
            result.push_back(temp->data);

            if (leftToRight) {
                if (temp->left != NULL) {
                    nextLevel.push(temp->left);
                }
                if (temp->right != NULL) {
                    nextLevel.push(temp->right);
                }
            } else {
                if (temp->right != NULL) {
                    nextLevel.push(temp->right);
                }
                if (temp->left != NULL) {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
    return result;
}

// Main function to test the zigzag traversal
int main() {
    // Creating a sample binary tree
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = zigZagTraversal(root);

    // Printing the result
    cout << "Zigzag Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
