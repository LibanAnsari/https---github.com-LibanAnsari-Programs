#include <bits/stdc++.h>
using namespace std;

class MyHash
{
private:
    int *arr;
    int cap, size;

public:
    MyHash(int c)
    {
        cap = c;
        size = 0;

        arr = new int[cap];
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1; // initializing all values as -1 in the array.
        }
    }
    ~MyHash()
    {
        delete[] arr;
    }


    int hash(int key)
    {
        return key % cap;
    }

    bool search(int key);
    bool insert(int key);
    bool erase(int key);
    void display();
};

bool MyHash::search(int key)
{
    int h = hash(key);
    int i = h;
    while (arr[i] != -1)
    {
        if (arr[i] == key)
        {
            return true;
        }
        i = (i + 1) % cap;
        if (i == h)
        {
            return false;
        }
    }
    return false;
}

bool MyHash::insert(int key)
{
    if (size == cap)
    {
        return false;
    }
    int i = hash(key);
    while (arr[i] != -1 and arr[i] != -2 and arr[i] == key)
    {
        i = (i + 1) % cap;
    }
    if (arr[i] == key)
    {
        return false;
    }

    arr[i] = key;
    size++;
    return true;
}

bool MyHash::erase(int key)
{
    if (size == 0)
    {
        return false;
    }
    int h = hash(key);
    int i = h;
    while (arr[i] != -1)
    {
        if (arr[i] == key)
        {
            arr[i] = -2;
            size--;
            return true;
        }
        i = (i + 1) % cap;
        if (i == h)
        {
            return false;
        }
    }
    return false;
}

void MyHash::display()
{
    for (int i = 0; i < cap; i++)
    {
        if (arr[i] >= 0)
        {
            cout << arr[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main()
{

    MyHash hashTable(7);

    hashTable.insert(49);
    hashTable.insert(56);
    
    hashTable.display();

    hashTable.insert(72);
    hashTable.erase(49);
    
    hashTable.display();

    return 0;
}