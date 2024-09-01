#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to serialize a tree into an array
vector<int> serialize(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node) {
            result.push_back(node->data);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1); // Using -1 to represent null nodes
        }
    }

    return result;
}

// Function to deserialize an array into a tree
Node* deSerialize(vector<int>& data) {
    if (data.empty()) return nullptr;

    Node* root = new Node(data[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < data.size()) {
        Node* node = q.front();
        q.pop();

        if (data[i] != -1) {
            node->left = new Node(data[i]);
            q.push(node->left);
        }
        i++;

        if (i < data.size() && data[i] != -1) {
            node->right = new Node(data[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// Helper function for in-order traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Example usage
int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    vector<int> serializedTree = serialize(root);
    Node* deserializedTree = deSerialize(serializedTree);

    cout << "In-order traversal of the deserialized tree: ";
    inorder(deserializedTree);
    cout << endl;

    return 0;
}
