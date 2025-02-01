#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int profit(vector<int>& V) {
    stack<int> s;
    int n = V.size();
    int totalProfit = 0;

    // Iterate through prices from the end to the beginning
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are less than the current price
        while (!s.empty() && s.top() < V[i]) {
            s.pop();
        }

        // If stack is empty, add the current price to total profit
        // Otherwise, add the difference between the next higher price and current price
        if (s.empty()) {
            totalProfit += V[i];
        } else {
            totalProfit += (s.top() - V[i]);
        }

        // Push current price onto the stack
        s.push(V[i]);
    }

    return totalProfit;
}

int main() {
    vector<int> prices = {5, 3, 8, 6, 2}; // No right Greater for 8 6 and 2
                       // (8-5)+(8-3)+8+6+2 = 24

    int totalProfit = profit(prices);
    
    cout << "Total Profit: " << totalProfit << endl; // Output the total profit
    
    return 0;
}
