//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int distinct(vector<vector<int>> M, int N)
{
    int hash[1001];
    // Initializing the hash array with 0.
    for (int i = 0; i < 1001; i++)
        hash[i] = 0;

    for (int i = 0; i < N; i++)
    {
        // Marking the elements in the first row as 1 in the hash array.
        hash[M[0][i]] = 1;
    }


    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Updating the hash array for each element in the matrix.
            // If an element is found for the current row, increment the value in the hash array by 1.
            if (hash[M[i][j]] == i)
            {
                hash[M[i][j]] = i + 1;
            }
        }
    }

    int count = 0;
    // Counting the number of elements that have a value equal to N in the hash array.
    for (int i = 0; i < 1001; i++)
    {
        if (hash[i] == N)
            count++;
    }
    // Returning the count of distinct elements.

    // for(int x : hash){
    //     cout << x << " ";
    // }
    
    return count;
}

int main()
{
    int N = 4;
    vector<vector<int>> M = {{2, 1, 4, 3},
                             {1, 2, 3, 2},
                             {3, 6, 2, 3},
                             {5, 2, 5, 3}};

    cout << distinct(M, N);

    return 0;
}