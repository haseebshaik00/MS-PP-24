#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    list<int> l;
    int cs=0;

public:
    Queue(){
        cs=0;
    }

    void push(int d){
        l.push_back(d);
        cs++;
    }

    void pop(){
        if(!isEmpty()){
            l.pop_front();
            cs--;
        }
    }

    int front(){
        return l.front();
    }

    bool isEmpty(){
        return cs==0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q;
    for(int i=0; i<12; i++)
        q.push(i);
    q.pop();
    q.pop();
    q.push(7);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
