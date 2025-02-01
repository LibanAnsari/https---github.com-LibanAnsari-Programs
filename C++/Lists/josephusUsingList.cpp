#include <iostream>
#include <list>
using namespace std;

int josephus(int n, int k) {
    list<int> l;
    // Populate the list with people numbered from 1 to n
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }
    
    auto it = l.begin();
    // Eliminate people in the Josephus manner until one remains
    while (l.size() > 1) {
        // Move the iterator k-1 steps forward
        for (int count = 1; count < k; count++) {
            it++;
            if (it == l.end()) {
                it = l.begin();
            }
        }
        // Erase the current person and move to the next person
        it = l.erase(it);
        if (it == l.end()) {
            it = l.begin();
        }
    }
    // Return the last remaining person's number
    return *it;
}

int main() {
    int n, k;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;
    
    int survivor = josephus(n, k);
    cout << "The position of the last remaining person is: " << survivor << endl;
    
    return 0;
}
