#include<bits/stdc++.h>
using namespace std;

int allOccurence(int a[], int n, int i, vector<int> &v, int k){
    if(i==n)
        return -1;
    if(a[i] == k)
        v.push_back(i);
    allOccurence(a, n, i+1, v, k);
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
    vector<int> v;
    allOccurence(a, n, 0, v, k);
    for(auto x:v)
        cout<<x<<" ";

    return 0;
}
