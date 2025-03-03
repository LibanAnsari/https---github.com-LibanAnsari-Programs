#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *next, *prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        } 
    };

    void addNode(int key, int value) { // Adds a node after dummy head (Most Recently Used)
        Node *newnode = new Node(key, value);
        newnode->next = head->next;
        newnode->prev = head;

        head->next->prev = newnode;
        head->next = newnode;
    }

    void deleteNode(Node *node) { // Deletes the given node from LL
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    int size; // Max size 
    unordered_map<int, Node*> hash; // Hash table <key, LL node>
    Node *head, *tail; // Dummy head and tail nodes

    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (hash.find(key) != hash.end()) { // Key exists
            Node *node = hash[key];
            int value = node->val;

            // Make the node most recently used
            hash.erase(key);
            deleteNode(node);
            addNode(key, value);

            hash[key] = head->next; // Add the node back in hash
            return value;
        }
        return -1; // Key not found
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) { // Key already present
            Node *node = hash[key];
            hash.erase(key);
            deleteNode(node);
        } 
        else if (hash.size() == size) { // Cache is full, remove LRU node
            hash.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(key, value); // Add new node
        hash[key] = head->next; // Update hash
    }
};

// Main function to test LRUCache
int main() {
    LRUCache cache(2); // Capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Get 1: " << cache.get(1) << endl; // Returns 10

    cache.put(3, 30); // Removes key 2 (LRU)
    cout << "Get 2: " << cache.get(2) << endl; // Returns -1 (not found)

    cache.put(4, 40); // Removes key 1 (LRU)
    cout << "Get 1: " << cache.get(1) << endl; // Returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // Returns 30
    cout << "Get 4: " << cache.get(4) << endl; // Returns 40

    return 0;
}
