#include<bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i=0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1){
    stack<int> s2;
    int n = s1.size();
    for(int i=0; i<n; i++){
        int d = s1.top();
        s1.pop();
        transfer(s1, s2, n-1-i);
        s1.push(d);
        transfer(s2, s1, n-1-i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s1;
    int n=5;
    for(int i=0; i<n; i++)
        s1.push(i);
    reverseStack(s1);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}
