#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
  public:
    static bool myCmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // sort by profit descending
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int, int>> arr;
        int maxDeadline = 0;

        for (int i = 0; i < profit.size(); i++) {
            arr.push_back({deadline[i], profit[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        sort(arr.begin(), arr.end(), myCmp);

        vector<int> slots(maxDeadline + 1, -1);
        int totalprof = 0, jobcount = 0;

        for (const auto &job : arr) {
            int dead = job.first;
            int prof = job.second;

            for (int i = dead; i >= 1; i--) {
                if (slots[i] == -1) {
                    slots[i] = prof;
                    totalprof += prof;
                    jobcount++;
                    break;
                }
            }
        }

        return {jobcount, totalprof};
    }
};

class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          vector<pair<int, int>> arr;
          int maxDeadline = 0;
  
          for (int i = 0; i < profit.size(); i++) {
              arr.push_back({deadline[i], profit[i]});
              maxDeadline = max(maxDeadline, deadline[i]);
          }
  
          // Sort by deadline (ascending)
          sort(arr.begin(), arr.end());
  
          priority_queue<int> pq;
          int totalprof = 0, jobcount = 0, index = profit.size() - 1;
  
          for (int day = maxDeadline; day >= 1; day--) {
              // Add jobs whose deadlines >= current day
              while (index >= 0 && arr[index].first >= day) {
                  pq.push(arr[index].second);
                  index--;
              }
  
              // Schedule the most profitable available job
              if (!pq.empty()) {
                  totalprof += pq.top();
                  pq.pop();
                  jobcount++;
              }
          }
  
          return {jobcount, totalprof};
      }
  };
  

int main() {
    Solution sol;

    // Example 1
    vector<int> deadline1 = {4, 1, 1, 1};
    vector<int> profit1 = {20, 10, 40, 30};
    vector<int> result1 = sol.jobSequencing(deadline1, profit1);
    cout << "Example 1: Jobs done = " << result1[0] << ", Total profit = " << result1[1] << endl;

    // Example 2
    vector<int> deadline2 = {2, 1, 2, 1, 1};
    vector<int> profit2 = {100, 19, 27, 25, 15};
    vector<int> result2 = sol.jobSequencing(deadline2, profit2);
    cout << "Example 2: Jobs done = " << result2[0] << ", Total profit = " << result2[1] << endl;

    // Example 3
    vector<int> deadline3 = {3, 1, 2, 2};
    vector<int> profit3 = {50, 10, 20, 30};
    vector<int> result3 = sol.jobSequencing(deadline3, profit3);
    cout << "Example 3: Jobs done = " << result3[0] << ", Total profit = " << result3[1] << endl;

    return 0;
}
