#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* createTree(vector<int> parent) {
    int n = parent.size();
    vector<Node*> nodes(n); // Fix: Initialize the vector with size 'n' <-------------
    
    // Create nodes for all indices
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i);
    }
    
    Node* root = NULL;
    
    // Assign children to their respective parent nodes
    for(int i = 0; i < n; i++) {
        if(parent[i] == -1) {
            root = nodes[i]; // Set the root node <-------------
        } else {
            Node* parentNode = nodes[parent[i]];
            if(parentNode->left == NULL) {
                parentNode->left = nodes[i]; // Assign as left child if not set <-------------
            } else {
                parentNode->right = nodes[i]; // Otherwise, assign as right child <-------------
            }
        }
    }
    
    return root; // Return the root node <-------------
}

// Utility function to print level order traversal of the tree using a queue
void printLevelOrder(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        cout << node->data << " ";
        
        if (node->left) {
            q.push(node->left);
        }
        
        if (node->right) {
            q.push(node->right);
        }
    }
}

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 3, 5};
    
    Node* root = createTree(parent);
    
    // Print level order traversal to verify the tree
    printLevelOrder(root);
    
    return 0;
}
