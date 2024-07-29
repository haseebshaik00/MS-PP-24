#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    return n*fact(n-1);
}

int fib(int n){
    if(n==1 | n==0)
        return n;
    return fib(n-1) + fib(n-2);
}

void inc(int n){
    if(n==0)
        return;
    inc(n-1);
    cout<<n<<" ";
}

void dec(int n){
    if(n==0)
        return;
    cout<<n<<" ";
    dec(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    cout<<fib(n)<<endl;
    inc(n);
    cout<<endl;
    dec(n);
    cout<<endl;

    return 0;
}
