#include <bits/stdc++.h>
using namespace std;

bool subarray(int arr[], int n){
    unordered_set<int> hash;
    int prefixsum = 0;
    for(int i = 0 ; i < n ; i++){
        prefixsum += arr[i];
        if(hash.find(arr[i]) != hash.end()){
            return true;
        }
        if(prefixsum == 0){
            return true;
        }
        hash.insert(arr[i]);
    }
    return false;
}


int main(){
    int arr[5] = {1,2,-3,4,5};
    cout << subarray(arr,5);
}