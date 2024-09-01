#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a singly-linked list node.
struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to convert a linked list to a complete binary tree
void convert(Node *head, TreeNode *&root) {
    if (head == NULL) {
        root = NULL;
        return;
    }

    // Create the root of the binary tree
    root = new TreeNode(head->data);
    queue<TreeNode*> q;
    q.push(root);

    head = head->next;
    while (head) {
        // Get the front node of the queue to attach children
        TreeNode *parent = q.front();
        q.pop();

        // Create the left child and push it to the queue
        TreeNode *lefttree = new TreeNode(head->data);
        parent->left = lefttree;
        q.push(lefttree);

        // Move to the next list node
        head = head->next;
        if (!head) break;

        // Create the right child and push it to the queue
        TreeNode *righttree = new TreeNode(head->data);
        parent->right = righttree;
        q.push(righttree);

        // Move to the next list node
        head = head->next;
    }
}

// Function to print the level order traversal of the tree
void printLevelOrder(TreeNode *root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Main function to test the convert function
int main() {
    // Example: Convert the linked list {1, 2, 3, 4, 5, 6, 7} to a binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = createLinkedList(arr, n);

    TreeNode *root = NULL;
    convert(head, root);

    // Print the level order traversal of the tree
    cout << "Level Order Traversal of the constructed Binary Tree:" << endl;
    printLevelOrder(root);

    return 0;
}
