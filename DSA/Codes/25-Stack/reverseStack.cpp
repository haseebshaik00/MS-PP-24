#include<bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i=0; i<n; ++i){
        s2.push(s1.top());
        s1.pop();
    }
}

void Reverse(stack<int> &s1) {
    stack<int> s2;
    int n = s1.size();
    for(int i=0; i<n; ++i){
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n-1-i);
        s1.push(x);
        transfer(s2, s1, n-1-i);
    }
}

void insertBottom(stack<int> &s1, int x){
    if(s1.empty()){
        s1.push(x);
        return;
    }
    int d = s1.top();
    s1.pop();
    insertBottom(s1, x);
    s1.push(d);
}

void Reverse(stack<int> &s1) {
    if(s1.empty()) return;
    int x = s1.top();
    s1.pop();
    Reverse(s1);
    insertBottom(s1, x);
}

void print(stack<int> s1){
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s1;
    int n=5;
    for(int i=1; i<=5; i++)
        s1.push(i);
    print(s1);
    reverseStack(s1);
    print(s1);
    reverseStackRec(s1);
    print(s1);

    return 0;
}
