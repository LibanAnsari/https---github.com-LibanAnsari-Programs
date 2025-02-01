#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // For tolower()
using namespace std;

bool isIsogram(string s) {
    vector<int> hash(26, 0);
    
    for (int i = 0; i < s.size(); i++) {
        char ch = tolower(s[i]);
        if (!isalpha(ch)) continue;  // Skip non-alphabetic characters
        
        hash[ch - 'a']++;
        if (hash[ch - 'a'] > 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    if (isIsogram(s)) {
        cout << s << " is an isogram." << endl;
    } else {
        cout << s << " is not an isogram." << endl;
    }

    return 0;
}
