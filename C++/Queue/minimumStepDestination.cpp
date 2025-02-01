#include <iostream>
#include <queue>
#include <utility> // for std::pair
using namespace std;

// Function to calculate the minimum distance
int minimum_distance(int Sx, int Sy, int Dx, int Dy) {
    // If the starting point is the same as the destination
    if (Sx == Dx && Sy == Dy) {
        return 0;
    }

    // Queue for BFS, storing pairs of (x, y) and distance
    queue<pair<pair<int, int>, int>> q; // ((x, y), distance)
    q.push({{Sx, Sy}, 0});

    // Visited array to avoid processing the same cell
    bool visited[1001][1001] = {false};
    visited[Sx][Sy] = true;

    // BFS Loop
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first.first;  // Current x coordinate
        int y = current.first.second; // Current y coordinate
        int dist = current.second;     // Current distance

        // Move to the right (x + 1, y)
        if (x + 1 <= Dx && !visited[x + 1][y]) {
            if (x + 1 == Dx && y == Dy) {
                return dist + 1; // Found the destination
            }
            visited[x + 1][y] = true;
            q.push({{x + 1, y}, dist + 1});
        }

        // Move up (x, y + 1)
        if (y + 1 <= Dy && !visited[x][y + 1]) {
            if (x == Dx && y + 1 == Dy) {
                return dist + 1; // Found the destination
            }
            visited[x][y + 1] = true;
            q.push({{x, y + 1}, dist + 1});
        }
    }

    // If we exhaust the queue without finding the destination
    return -1;
}

int main() {
    // Sample inputs
    int testCases[3][4] = {
        {1, 1, 2, 2}, // Test case 1: Starting at (1, 1) to (2, 2)
        {1, 1, 3, 3}, // Test case 2: Starting at (1, 1) to (3, 3)
        {2, 3, 1, 1}  // Test case 3: Starting at (2, 3) to (1, 1) - this should return -1
    };

    // Number of test cases
    int T = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < T; i++) {
        int Sx = testCases[i][0];
        int Sy = testCases[i][1];
        int Dx = testCases[i][2];
        int Dy = testCases[i][3];
        cout << "Test Case " << (i + 1) << ": "
             << "Minimum Distance from (" << Sx << ", " << Sy << ") to ("
             << Dx << ", " << Dy << ") is: "
             << minimum_distance(Sx, Sy, Dx, Dy) << endl;
    }

    return 0;
}
