#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int unique_substring(const string& str) {
    unordered_set<string> uniqueSubstrings;
    
    int n = str.length();
    
    // Generate all substrings
    for (int i = 0; i < n; ++i) {
        string currentSubstring = "";
        for (int j = i; j < n; ++j) {
            currentSubstring += str[j];
            uniqueSubstrings.insert(currentSubstring);
        }
    }
    
    // The size of the set gives the count of unique substrings
    return uniqueSubstrings.size();
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int result = unique_substring(str);
    cout << "Total number of unique substrings: " << result << endl;

    return 0;
}
