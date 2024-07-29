#include<bits/stdc++.h>
using namespace std;

int binaryS(int a[], int k, int i, int j){
    if(i>j)
        return -1;
    int mid = (i+j)/2;
    if(a[mid] == k)
        return mid;
    else if(a[mid] < k)
        return binaryS(a, k, mid+1, j);
    else
        return binaryS(a, k, i, mid-1);
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
    cout<<binaryS(a, k, 0, n-1);

    return 0;
}
