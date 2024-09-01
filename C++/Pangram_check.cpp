//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
    // PANGRAM IS A SENTENCE WHICH CONTAINS ALL ALPHABETS A-Z
*/



bool check_pangram(string &s , int &n){
    // lowering the characters in the string
    for(int i = 0 ; i < n ; i++){
        s[i] = tolower(s[i]);
    }

    int count[25] = {0};
    // creating a zero count array , 25 since indexing starts from 0

    for(int i = 0 ; i < n ; i++){
        if('a' <= s[i] <= 'z'){
            count[s[i] - 'a']++;
        }
    }

    for(int i = 0 ; i < 26 ; i++){
        if(count[i] == 0){
            return false;
        }
    }

    return true;
    
}


int main(){
    string s;
    cout << "Enter the string: ";
    getline(cin,s);
    int n = s.length();
    
    cout << check_pangram(s,n);
    
    // cout << s;
    return 0;
}