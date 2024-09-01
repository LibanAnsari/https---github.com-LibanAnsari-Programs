#include <iostream>
#include <vector>
#include <queue>

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

vector<int> rightView(Node* root) {
    if (root == NULL) return {}; // Return an empty vector if the tree is empty

    vector<int> res; // To store the right view of the tree
    queue<Node*> q;  // Queue to facilitate level order traversal

    q.push(root);

    while (!q.empty()) {
        int lvlSize = q.size(); // Number of nodes at the current level

        for (int i = 0; i < lvlSize; i++) {
            Node* node = q.front(); // Get the front node
            q.pop(); // Remove it from the queue

            // If it's the last node of this level, add it to the result <----
            if (i == lvlSize - 1) { // Correct condition to get the rightmost node <----
                res.push_back(node->data);
            }

            // Add the left child to the queue if it exists
            if (node->left != NULL) {
                q.push(node->left);
            }

            // Add the right child to the queue if it exists
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }

    return res; // Return the result vector containing the right view
}

// Example usage
int main() {
    // Construct a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    /*
            1
          /   \
         2     3
        / \     \
       4   5     6

    */

    vector<int> right_view = rightView(root);
    cout << "Left view of the tree: ";
    for (int val : right_view) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
