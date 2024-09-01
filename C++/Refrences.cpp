#include <bits/stdc++.h>
using namespace std;

void reverse(int &a, int &b)
{
    int temp = 0, digit;
    while (a != 0)
    {
        digit = a % 10;
        temp = temp*10 + digit * 10;
        a = a / 10;
    }
    a = temp;

    temp = 0;
    while (b != 0)
    {
        digit = b % 10;
        temp = temp*10 + digit * 10;
        b = b / 10;
    }
    b = temp;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 8765;
    int b = 4321;
    // reverse(a, b);
    // swap(a, b);
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;
}