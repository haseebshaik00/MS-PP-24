#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    stack<int> s1, s2;

public:
    void push(int d){
        s1.push(d);
    }

    void pop(){
        if(s1.empty())
            return;
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front(){
        if(s1.empty())
            return -1;
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int d = s1.top();
        s2.push(s1.top());
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return d;
    }

    bool isEmpty(){
        return s1.size()==0;
    }

    int size(){
        return s1.size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q;
    for(int i=1; i<=5; i++)
        q.push(i);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
