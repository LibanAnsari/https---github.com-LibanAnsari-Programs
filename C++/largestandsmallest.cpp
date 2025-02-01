#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    
    int arr[] = {1,2,3,5,6,7};

    int largest = arr[0];
    int smallest = arr[0];
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }

    cout << largest << " "<< smallest;    

    return 0;
}
