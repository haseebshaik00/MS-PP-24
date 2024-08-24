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

void insertAtBottom(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int d = s.top();
    s.pop();
    insertAtBottom(s, n);
    s.push(d);
}

void reverseStackRec(stack<int> &s){
    if(s.empty())
        return;
    int d = s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s, d);
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
