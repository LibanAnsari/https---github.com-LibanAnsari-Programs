#include <iostream>
#include <stack>
using namespace std;

class Solution{
    int minEle;
    stack<int> s;
    stack<int> MinStack;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()){
               return -1;
           }
           return MinStack.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()){
               return -1;
           }
           int item = s.top();
           s.pop(); MinStack.pop();
           return item;
       }
       
       /*push element x into the stack*/
       void push(int x){
           s.push(x);
           if(MinStack.empty() or x < MinStack.top()){
               MinStack.push(x);
           }else{
               MinStack.push(MinStack.top());
           }
       }
};

int main() {
    Solution stack;
    
    stack.push(3);
    stack.push(5);
    cout << "Minimum Element: " << stack.getMin() << endl; // 3

    stack.push(2);
    stack.push(1);
    cout << "Minimum Element: " << stack.getMin() << endl; // 1

    stack.pop();
    cout << "Minimum Element: " << stack.getMin() << endl; // 2

    stack.pop();
    cout << "Minimum Element: " << stack.getMin() << endl; // 3

    return 0;
}
