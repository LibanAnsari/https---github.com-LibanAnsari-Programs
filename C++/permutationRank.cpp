#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int RankMe(string str) {
    // Sort the string to start from the lexicographically smallest permutation
    string sorted_str = str;
    sort(sorted_str.begin(), sorted_str.end());
    
    int rank = 1;  // Start rank from 1
    
    // Generate permutations until we reach the target string
    do {
        if (sorted_str == str) {
            return rank; // Return the rank when we reach the input string
        }
        rank++;
    } while (next_permutation(sorted_str.begin(), sorted_str.end()));
    
    return rank; // Should not reach here if str is valid and within constraints
}

int main() {
    // Example input
    int T = 2;  // Number of test cases
    string test_cases[] = {"ABC", "CAB"};
    
    for (int i = 0; i < T; i++) {
        string str = test_cases[i];
        cout << "Rank of string '" << str << "' is: " << RankMe(str) << endl;
    }

    return 0;
}
