#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string TieBreak(string names[], int n) {
    unordered_map<string, int> m;
    
    // Storing the frequency of each name.
    for (int i = 0; i < n; i++) {
        m[names[i]]++;
    }
    
    int max_freq = 0;
    string winner = "";
    
    // Finding the name with the highest frequency and tie-breaking lexicographically.
    for (auto x : m) {
        if (x.second > max_freq) {
            winner = x.first;
            max_freq = x.second;
        } else if (x.second == max_freq) {
            // If there's a tie, choose the lexicographically smaller name
            if (x.first < winner) {
                winner = x.first;
            }
        }
    }
    return winner;
}

int main() {
    int n;
    cout << "Enter the number of names: ";
    cin >> n;

    string names[n];
    cout << "Enter the names: ";
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    string result = TieBreak(names, n);
    
    cout << "Winner: " << result << endl;

    return 0;
}
