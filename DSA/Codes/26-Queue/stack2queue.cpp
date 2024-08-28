#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    queue<int> q1, q2;

public:
    void push(int d){
        q1.push(d);
    }

    void pop(){
        if(q1.empty())
            return;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    int top(){
        if(q1.empty()) return -1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int d = q1.front();
        q1.pop();
        q2.push(d);
        swap(q1, q2);
        return d;
    }

    int size(){
        return q1.size();
    }

    bool isEmpty(){
        return q1.empty();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
