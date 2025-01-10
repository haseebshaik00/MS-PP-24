#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool compare(int a, int b){
    return a>b; // > decreasing
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a,0,n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n, compare);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
