# include<bits/stdc++.h>
using namespace std;

char oddCharacter(const string &s1 ,const string &s2, int &n1 , int &n2){
    // creating a zero count array of 256
    int count[256] = {0};

    // incrementing the count of charcters in s1 in count array
    for(int i = 0 ; i < n1 ; i++){
        count[s1[i]]++;
    }

    // decrementing the count of charcters in s2 in count array
    for(int i = 0 ; i < n2 ; i++){
        count[s2[i]]--;
    }

    for(int i = 0 ; i < 256 ; i++){
        if(count[i] != 0){
            return char(i);
        }
    }
    return '1';

}


int main(){
    string s1;
    cout << "Enter the string 1: ";
    getline(cin,s1);

    string s2;
    cout << "Enter the string s2: ";
    getline(cin,s2);

    int n1 = s1.length();
    int n2 = s2.length();

    cout << oddCharacter(s1,s2,n1,n2) << endl;

}