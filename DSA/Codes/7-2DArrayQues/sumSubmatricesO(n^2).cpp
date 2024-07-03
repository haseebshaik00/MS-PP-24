#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, s=0;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            s += a[i][j] * (i+1)*(j+1) * (m-i)*(n-j);
    cout<<s<<endl;

    return 0;
}
