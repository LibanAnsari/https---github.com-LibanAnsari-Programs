#include <bits/stdc++.h>
using namespace std;

class MyHash
{
private:
    int BUCKET;
    list<int> *table;

public:
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[b];
    }
    ~MyHash()
    {
        delete[] table;
    }

    int hash(int key)
    {
        return key % BUCKET;
    }

    void insert(int key);
    bool search(int key);
    void remove(int key);
    void display();
};

void MyHash::insert(int key)
{
    int i = hash(key);
    table[i].push_back(key);
}

void MyHash::remove(int key)
{
    int i = hash(key);
    table[i].remove(key);
}

bool MyHash::search(int key)
{
    int i = hash(key);
    for (auto x : table[i])
    {
        if (x == key)
        {
            cout << "Found!" << endl;
            return true;
        }
    }
    cout << "Not Found!" << endl;
    return false;
}

void MyHash::display()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i << ": ";
        for (auto x : table[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    MyHash h(5);
    h.insert(10);
    h.insert(7);
    h.insert(2);

    h.display();

    return 0;
}