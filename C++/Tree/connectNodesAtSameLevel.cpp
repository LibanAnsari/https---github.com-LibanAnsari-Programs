#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node with a nextRight pointer
struct Node {
    int data;
    Node *left, *right, *nextRight;
    Node(int x) : data(x), left(NULL), right(NULL), nextRight(NULL) {}
};

class Solution {
public:
    // Function to connect nodes at the same level
    void connect(Node *root) {
        if (root == NULL) {
            return;
        }

        // Use a queue to traverse the tree level by level
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            // Process all nodes at the current level
            for (int i = 0; i < n; i++) {
                Node *node = q.front(); q.pop();

                // Set nextRight for the current node
                if(i == n - 1){
                    node->nextRight = NULL;  // Last node in the level
                } else {
                    node->nextRight = q.front();  // Point to the next node in the queue
                }

                // Enqueue left and right children of the current node
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
    }
};

// Helper function to print the nextRight of each node at a level
void printNextRight(Node *root) {
    if (root == NULL) return;

    Node *current = root;
    while (current != NULL) {
        cout << current->data << " -> ";
        if (current->nextRight) {
            cout << current->nextRight->data << " ";
        } else {
            cout << "NULL ";
        }
        current = current->nextRight;
    }
    cout << endl;
}

// Helper function to create a binary tree node
Node* createNode(int data) {
    return new Node(data);
}

// Main function to test the connect function
int main() {
    /* Example Binary Tree
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    // Creating the binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Connect nodes at the same level
    Solution solution;
    solution.connect(root);

    // Print the nextRight of each level starting from the root
    cout << "NextRight of nodes at each level:" << endl;
    printNextRight(root);
    printNextRight(root->left);
    printNextRight(root->left->left);

    return 0;
}
