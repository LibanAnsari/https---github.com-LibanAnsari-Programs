#include <bits/stdc++.h>
using namespace std;

/*
    // TWO STRINGS ARE ANAGRAM WHO HAVE SAME CHARACTERS
*/

bool check_anagram(const string &s1 , const string &s2 , int &n1 , int &n2)
{
    if (n1 != n2)
    {
        return false;
    }

    int count[256] = {0}; // count array for 256 characters

    for(int i = 0 ; i < n1 ; i++){
        count[s1[i]]++; //incrementing count of s1 characters
    }

    for(int i = 0 ; i < n2 ; i++){
        count[s2[i]]--; //decrementing count of s2 characters
    }

    for(int i = 0 ; i < 256 ; i++){
        if(count[i] != 0){
            return false;
        }
    }

    return true;
    

}

int main()
{
    string s1;
    cout << "Enter the string 1: ";
    getline(cin, s1);

    string s2;
    cout << "Enter the string s2: ";
    getline(cin, s2);

    int n1 = s1.length();
    int n2 = s2.length();

    cout << check_anagram(s1, s2, n1, n2) << endl;
}