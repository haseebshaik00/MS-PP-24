#include<bits/stdc++.h>
using namespace std;

int lastOccurence(int a[], int n, int k){
    if(n==0)
        return -1;
    int i = lastOccurence(a+1, n-1, k);
    if(i==-1){
        if(a[0] == k) return 0;
        else return -1;
    }
    else
        return i+1;
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
    cout<<lastOccurence(a, n, k)<<endl;

    return 0;
}
