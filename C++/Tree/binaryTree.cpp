#include <bits/stdc++.h>
using namespace std;

/*
    BINARY TREE
*/

class Node{
public:
    int data;
    Node *left , *right;

    Node(int k){
        data = k;
        right = left = NULL;
    }
};

// InOrder Traversal
void inOrder(Node *root){
    // Recursive
    // if(root != NULL){
    //     inOrder(root->left);
    //     cout << root->data << " ";
    //     inOrder(root->right);
    // }

    // Iterative
    if(root == NULL) return;

    stack<Node*> s;
    Node *node = root;

    while(node != NULL or !s.empty()){
        while(node != NULL){
            s.push(node);
            node = node->left;
        }
        node = s.top(); s.pop();
        cout << node->data << " ",
        node = node->right;
    }
}

// PreOrder Traversal
void preOrder(Node *root){
    // Recursive
    // if(root != NULL){
    //     cout << root->data << " ";
    //     preOrder(root->left);
    //     preOrder(root->right);
    // }

    // Iterative
    if(root == NULL) return;

    stack<Node*> s;
    Node *node = root;

    while(node != NULL or !s.empty()){
        while(node != NULL){
            
            cout << node->data << " ";

            if(node->right != NULL){
                s.push(node->right);
            }
            node = node->left;
        }
        if(!s.empty()){
            node = s.top();
            s.pop();
        }
    }
}

// PostOrder Traversal
void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Height of Binary Tree
int calHeight(Node *root){
    if(root == NULL){
        return 0;
    }else{
        return max(calHeight(root->left),calHeight(root->right)) + 1;
    }
}

// Diameter of Binary Tree (no. of nodes between the leftmost and rightmost element)
int calDiameter(Node *root , int *height){
    if(root == NULL){
        *height = 0;
        return 0;
    }

    int lh = 0 , rh = 0;
    int lDiameter = calDiameter(root->left , &lh);
    int rDiameter = calDiameter(root->right , &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh , rh) + 1;

    return max(currDiameter , max(lDiameter , rDiameter));   
}

// Print k Nodes from root
void printkNodes(Node *root , int k){
    if(root == NULL) return;
    if(k == 0){
        cout << root->data << " ";
    }else{
        printkNodes(root->left,k-1);
        printkNodes(root->right,k-1);
    }
}

// Print Level Order
void printLevelOrder(Node *root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        if(node != NULL){
            cout << node->data << " ";
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }

        }else if(!q.empty()){
            q.push(NULL);
        }
        if(node == NULL){
            cout << "$ ";
        }
    }
}

// Insert in Binary Tree
void insertInBinaryTree(Node *root , int key){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *node = q.front();
        q.pop();

        if(node->left == NULL){
            node->left = new Node(key);
            break;
        }else{
            node = node->left;
        }

        if(node->right == NULL){
            node->right = new Node(key);
            break;
        }else{
            node = node->right;
        }
    }

}

// Number of elements in Binary Tree
int sizeOfBinaryTree(Node *root){
    if(root == NULL){
        return 0;
    }else{
        return sizeOfBinaryTree(root->left) + sizeOfBinaryTree(root->right) + 1;
    }

}

// Maximum element in Binary Tree
int maxOfBinaryTree(Node *root){
    if(root == NULL) return INT_MIN;
    else{
        return max(root->data,max(maxOfBinaryTree(root->left),maxOfBinaryTree(root->right)));
    }
}


int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    /*
            10
           /  \
         20    30
              /  \
            40    50

    */

    cout << "InOrder Traversal:\n";
    inOrder(root); cout << endl;

    cout << "PreOrder Traversal:\n";
    preOrder(root); cout << endl;

    cout << "PostOrder Traversal:\n";
    postOrder(root); cout << endl;

    cout << "Height of the tree is: " << calHeight(root) << endl;
    int height = 0;
    cout << "Diameter of the tree is: " << calDiameter(root , &height) << endl;

    cout << "k Nodes:" << endl;
    printkNodes(root,2); cout << endl; //0 for root node , 1 for first level nodes , 2 for second level nodes...

    cout << "Level Order Traversal:\n";
    printLevelOrder(root); cout << endl;

    cout << "Size of the tree is: " << sizeOfBinaryTree(root) << endl;

    cout << "Maximum element of the tree is: " << maxOfBinaryTree(root) << endl;

    insertInBinaryTree(root , 60);
    cout << "Level Order Traversal:\n";
    printLevelOrder(root); cout << endl;

    return 0;
}
