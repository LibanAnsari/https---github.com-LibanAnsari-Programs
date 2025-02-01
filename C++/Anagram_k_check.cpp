#include <bits/stdc++.h>
using namespace std;

bool areKAnagrams(string str1, string str2, int k) {
    // If the strings are of different lengths, they can't be k-anagrams
    if (str1.size() != str2.size()) return false;

    // Frequency count array for all characters in 'a' to 'z'
    vector<int> hash(26, 0);

    // Count frequencies for characters in str1
    for (char c : str1) {
        hash[c - 'a']++;
    }

    // Subtract frequencies for characters in str2
    for (char c : str2) {
        hash[c - 'a']--;
    }

    // Calculate the number of changes needed to match str1 with str2
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (hash[i] > 0) {
            count += hash[i];
        }
    }

    // Check if the required changes are within the allowed k changes
    return count <= k;
}

int main() {
    // Input strings and k value
    string str1, str2;
    int k;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    cout << "Enter value of k: ";
    cin >> k;

    // Check if they are k-anagrams
    bool result = areKAnagrams(str1, str2, k);

    // Output result
    if (result) {
        cout << "The strings are k-anagrams." << endl;
    } else {
        cout << "The strings are not k-anagrams." << endl;
    }

    return 0;
}
