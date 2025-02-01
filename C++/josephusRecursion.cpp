#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1) {
        return 1;
    }
    return (josephus(n - 1, k) + k - 1) % n + 1;
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
