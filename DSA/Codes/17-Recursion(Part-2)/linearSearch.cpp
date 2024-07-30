#include<bits/stdc++.h>
using namespace std;

// First Occurence

// Increasing
int linearS(int a[], int n, int k){
    if(n==0)
        return -1;
    if(a[0] == k)
        return 0;
    int i = linearS(a+1, n-1, k);
    if(i == -1)
        return -1;
    return i+1;
}

// Decreasing
int linearSLoop(int a[], int n, int i, int k){
    if(i==n)
        return -1;
    if(a[i] == k)
        return i;
    return linearSLoop(a, n, i+1, k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>k;
    cout<<linearS(a, n, k)<<endl;
    cout<<linearSLoop(a, n, 0, k)<<endl;

    return 0;
}
