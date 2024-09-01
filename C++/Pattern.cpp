//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void invTriangleWall(int s){
    
    //Write your code here
    for(int row = 1 ; row <= s ; row++){
        for(int col = s - row + 1 ; col > 0 ; col--){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    invTriangleWall(n);

    return 0;
}