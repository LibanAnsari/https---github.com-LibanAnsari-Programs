#include <bits/stdc++.h>
using namespace std;

void binSort(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {

        do
        {
            i++;
        } while (arr[i] == 0);

        do
        {
            j--;
        } while (arr[j] == 1);

        if (i >= j)
        {
            return;
        }
        swap(arr[i], arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,0,1,1,0};
    cout << "Before sorting: " << endl;
    for(int i = 0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    binSort(arr,5);
    cout << "After sorting: " << endl;
    for(int i = 0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
