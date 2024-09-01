#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* lca(Node* root, int n1, int n2) {
    // Base case
    if (root == nullptr)
        return nullptr;

    // If either n1 or n2 matches with root's key, report the presence
    // by returning root (Note that if a key is ancestor of other,
    // then the ancestor key becomes LCA)
    if (root->data == n1 || root->data == n2)
        return root;

    // Look for keys in left and right subtrees
    Node* left_lca = lca(root->left, n1, n2);
    Node* right_lca = lca(root->right, n1, n2);

    // If both of the above calls return Non-null, then one key
    // is present in one subtree and other is present in other,
    // so this node is the LCA
    if (left_lca && right_lca)
        return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != nullptr) ? left_lca : right_lca;
}

// Function to insert nodes in level order
Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Driver code
int main() {
    int n1 = 3, n2 = 4;
    int arr[] = {5, 2, -1, 3, 4}; // Use -1 to represent null nodes
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Node* root = insertLevelOrder(arr, root, 0, n);
    Node* lca_node = lca(root, n1, n2);
    
    if (lca_node != nullptr)
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca_node->data;
    else
        cout << "LCA does not exist";
    
    return 0;
}
