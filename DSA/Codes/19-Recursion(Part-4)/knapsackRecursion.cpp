#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[], int p[], int n, int k){
    if(n==0 || k==0)
        return 0;
    int inc=0, exc=0;
    if(w[n-1]<=k)
        inc = p[n-1] + knapsack(w, p, n-1, k-w[n-1]);
    exc = knapsack(w, p, n-1, k);
    return max(inc, exc);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    int w[n], p[n];
    memset(w, 0, n);
    memset(p, 0, n);
    for(int i=0; i<n; i++)
        cin>>w[i];
    for(int i=0; i<n; i++)
        cin>>p[i];
    cin>>k;
    cout<<knapsack(w, p, n, k);

    return 0;
}
