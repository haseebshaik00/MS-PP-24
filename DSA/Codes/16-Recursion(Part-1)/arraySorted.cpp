#include<bits/stdc++.h>
using namespace std;

bool isArraySorted(int a[], int n){
    if(n==1)
        return true;
    if(a[0]<=a[1] & isArraySorted(a+1, n-1))
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<isArraySorted(a, n);

    return 0;
}
