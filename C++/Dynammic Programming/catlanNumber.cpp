#include <bits/stdc++.h>
using namespace std;

long long findCatalan(int n) {
    vector<long long> catalan(n + 1, 0);
    catalan[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }

    return catalan[n];
}

int main() {
    int n = 4;
    cout << findCatalan(n) << endl; // Output: 14
    return 0;
}
