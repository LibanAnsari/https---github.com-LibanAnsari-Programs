#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    
    // Function to count numbers with exactly 3 divisors
    int exactly3Divisors(int N) {
        // Initialize counter to zero
        int counter = 0; 
        // Limit the search up to sqrt(N)
        N = sqrt(N);
        // Loop from 1 to sqrt(N)
        for (int i = 1; i <= N; i++) {
            // If i is prime, then i^2 has exactly 3 divisors
            if(isPrime(i))
                counter++;
        }
        return counter;
    }
};

int main() {
    Solution solution;
    int N;
    cout << "Enter a number N: ";
    cin >> N;
    int result = solution.exactly3Divisors(N);
    cout << "Count of numbers with exactly 3 divisors up to " << N << " is: " << result << endl;
    return 0;
}
