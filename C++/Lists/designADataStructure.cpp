#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

list<int> l;

// Inserts an integer at the end of the data structure.
void insert(int x) {
    l.push_back(x);
}

// Prints the elements of the data structure
// The new line is given by the driver's code.
void print() {
    for (auto x : l) {
        cout << x << " ";
    }
    cout << endl;
}

// Replaces the first occurrence of x with the sequence.
void replace(int x, vector<int> sequence) {
    auto it = find(l.begin(), l.end(), x);
    if (it == l.end()) {
        return; // x not found, no replacement done
    }
    // Erase the element x and insert the sequence at that position
    it = l.erase(it);
    l.insert(it, sequence.begin(), sequence.end());
}

int main() {
    // Insert elements
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    cout << "List after insertion: ";
    print();

    // Replace the first occurrence of 3 with the sequence {9, 8, 7}
    vector<int> sequence = {9, 8, 7};
    replace(3, sequence);

    cout << "List after replacement: ";
    print();

    return 0;
}
