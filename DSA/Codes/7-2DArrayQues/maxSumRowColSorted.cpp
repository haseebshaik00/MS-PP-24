#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, smax=INT_MIN;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    // take suffix matrix - find largest cell
    for(int i=m-1; i >= 0; i--)
        for(int j=n-2; j>=0; j--)
            a[i][j] += a[i][j+1];
    for(int j=n-1; j>=0; j--)
        for(int i=m-2; i>=0; i--)
            a[i][j] += a[i+1][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            smax = max(a[i][j], smax);
    cout<<smax<<endl;

    return 0;
}
