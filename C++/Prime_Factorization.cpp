#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void primefact(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            int x = i;
            while (n % x == 0)
            {
                cout << i << " ";
                x = x * i;
            }
        }
    }
}
/*
    prime factorization of 50
    2 5 5
    1 2 3 4 5 6 ... 50
    2*2 + 5*5 + 5*5
*/

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    primefact(num);
}