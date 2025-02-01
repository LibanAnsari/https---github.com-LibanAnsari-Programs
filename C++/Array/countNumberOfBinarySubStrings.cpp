#include <iostream>
#include <string>
using namespace std;

long binarySubstring(int n, string S) {
    long ones = 0;
    // Count the number of '1's in the string
    for (int i = 0; i < n; i++) {
        if (S[i] == '1') {
            ones++;
        }
    }
    // The number of valid substrings that start and end with '1' is given by ones * (ones - 1) / 2
    return (ones * (ones - 1)) / 2;
}

int main() {
    string S;
    cout << "Enter a binary string: ";
    cin >> S;
    
    long result = binarySubstring(S.size(), S);
    cout << "Number of substrings starting and ending with '1': " << result << endl;

    return 0;
}
