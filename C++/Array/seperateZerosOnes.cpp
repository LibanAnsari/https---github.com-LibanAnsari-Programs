#include <iostream>
#include <vector>
using namespace std;

void separate(vector<int> &numbers) {
    
    int i = -1;
    int j = numbers.size();

    while(1){
        do
        {
            i++;
        }while(numbers[i] == 0);
        do
        {
            j--;
        }while(numbers[j] == 1);
        if(i >= j) return;
        swap(numbers[i],numbers[j]);
    }

}

int main() {
    vector<int> numbers = {1,1,1,1,1,0,1};
    
    separate(numbers);

    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
