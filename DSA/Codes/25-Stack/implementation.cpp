#include<bits/stdc++.h>
using namespace std;

template <class T>
class Stack{
private:
    vector<T> v;

public:
    void push(T x){
        v.push_back(x);
    }

    void pop(){
        if(!v.empty()){
            v.pop_back();
        }
    }

    T top(){
        if(v.empty()) return -1;
        return v.back();
    }

    void print(){
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    bool isEmpty(){
        return v.size()==0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack<char> s;
    for(int i=1; i<=5; i++)
        s.push('a');
    s.print();
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
