#include <iostream>
#include <vector>
using namespace std;

bool isprime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

vector<int> prime_at_prime(vector<int> v) {
    vector<int> res;
    for(int i = 2; i < v.size(); i++) {
        if(isprime(i) && isprime(v[i - 1])) {
            res.push_back(v[i - 1]);
        }
    }
    return res;
}

int main() {
    vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    
    vector<int> result = prime_at_prime(v);
    cout << "Prime numbers at prime indices: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
