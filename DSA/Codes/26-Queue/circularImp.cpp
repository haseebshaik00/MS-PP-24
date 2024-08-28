#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    int *a, f, r, cs, n;

    public:
    Queue(int qs=10){
        a = new int(10);
        n = qs; f=0; r=qs-1; cs=0;
    }

    void push(int d){
        if(!isFull()){
            r = (r+1)%n;
            a[r] = d;
            cs++;
        }
    }

    void pop(){
        if(!isEmpty()){
            f = (f+1)%n;
            cs--;
        }
    }

    int front(){
        return a[f];
    }

    bool isEmpty(){
        return cs==0;
    }

    bool isFull(){
        return cs==n;
    }

    ~Queue(){
        if(a!=NULL){
            delete []a;
            a=NULL;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q(10);
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
