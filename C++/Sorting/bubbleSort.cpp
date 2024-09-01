# include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    int arr[n] = {34,45,456,23,1,-23};

    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    for(int i : arr){
        cout << i << " ";
    }


    return 0;
}