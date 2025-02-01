#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    stack<int> s;                // Stack to hold elements
    int n = arr.size();          // Size of the input array
    vector<int> res(n);          // Vector to store the result

    // Iterate from the end of the array to the beginning
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack while they are less than or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        // If the stack is empty, there's no greater element, otherwise it's the top of the stack
        res[i] = (s.empty()) ? -1 : s.top();
        // Push the current element onto the stack
        s.push(arr[i]);
    }
    return res; // Return the result
}

int main() {
    vector<int> arr = {1, 3, 2,  4}; // Example array
                    //[3, 4, 4, -1]
    vector<int> result = nextLargerElement(arr);
    
    cout << "Next Larger Elements: ";
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
