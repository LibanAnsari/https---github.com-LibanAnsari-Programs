#include <iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;

    cout << a << " " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "After Swapping" << endl;
    cout << a << " " << b;

}