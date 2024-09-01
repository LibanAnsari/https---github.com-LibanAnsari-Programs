#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert nodes in level order
Node* insertLevelOrder(vector<int>& arr, int i, int n) {
    if (i >= n) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}

// Function to calculate the vertical width of a binary tree
int verticalWidth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    
    // Initialize min and max horizontal distance
    int minHD = 0, maxHD = 0;
    
    // Queue for level order traversal that stores nodes and their horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        Node* node = temp.first;
        int hd = temp.second;
        
        // Update min and max horizontal distances
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
        
        // Traverse the left subtree
        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }
        
        // Traverse the right subtree
        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }
    
    // The width is maxHD - minHD + 1
    return (maxHD - minHD + 1);
}

int main() {
    // Given input
    string input = "33 3 21 16 19 20 24 7 3";
    
    // Convert input string to a vector of integers
    vector<int> arr;
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    
    // Construct the binary tree from the level order input
    Node* root = insertLevelOrder(arr, 0, arr.size());
    
    // Compute and print the vertical width of the binary tree
    cout << "The vertical width of the binary tree is: " << verticalWidth(root) << endl;
    
    return 0;
}
