#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    // Constructor to initialize a node with given data and null children
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    // Function to check if two trees are identical
    bool isIdentical(Node *r1, Node *r2)
    {
        // If both trees are empty, they are identical
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        
        // If one tree is empty and the other is not, they are not identical
        if (r1 == NULL || r2 == NULL) {
            return false;
        } else {
            // Check if current nodes' data are the same
            bool cond1 = (r1->data == r2->data);
            // Recursively check left subtrees
            bool cond2 = isIdentical(r1->left, r2->left);
            // Recursively check right subtrees
            bool cond3 = isIdentical(r1->right, r2->right);
            
            // Both conditions must be true for trees to be identical
            if (cond1 && cond2 && cond3) {
                return true;
            } else {
                return false;
            }
        }
    }
};

// Example usage
int main() {
    // Creating a sample tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    
    // Creating a sample tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    
    Solution solution;
    if (solution.isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }
    
    return 0;
}
