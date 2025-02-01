#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(vector<int> &arr) {
    stack<int> s;               // Stack to store indices of prices
    vector<int> res(arr.size()); // Vector to store the span results

    // Loop through each price
    for (int i = 0; i < arr.size(); i++) {
        // Pop elements from the stack while the current price is greater than or equal to the price at the index on top of the stack
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        // If the stack is empty, span is i + 1, else span is i - s.top()
        res[i] = s.empty() ? (i + 1) : (i - s.top());
        // Push the current index onto the stack
        s.push(i);
    }
    return res; // Return the calculated spans
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85}; // Example prices
    vector<int> spans = calculateSpan(prices);
    
    cout << "Stock prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;

    cout << "Calculated spans: ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}
