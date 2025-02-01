#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int firstMissingPositive(vector<int>& arr) {
    int n = arr.size();

    // THE ANSWER WILL LIE IN RANGE OF [1,len(arr)+1]

    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= 0){
            arr[i] = n+1; // setting all zeros and negatives as a number larger than the array size
        }
    }

    // use index of arr as a hashset
    // for every arr[i] we set mark arr[i]-1 index as negative to mark its presence.
    for(int i = 0 ; i < n ; i++){
        int index = abs(arr[i]) - 1;
        // if a number is already negative then it's repeating
        if(index >= 0 and index < n and arr[index] > 0){
            arr[index] = -arr[index];
        }
    }

    // search for index whose number is not marked as negative.
    for(int i = 0 ; i < n ; i++){
        if(arr[i] >= 0){
            return i+1; // found the number
        }
    }
    return n+1; // the last number is not present
}

int main() {
    vector<int> arr = {3, 4, -1, 1};
    int result = firstMissingPositive(arr);
    cout << "First Missing Positive: " << result << endl; // Expected Output: 2

    return 0;
}
