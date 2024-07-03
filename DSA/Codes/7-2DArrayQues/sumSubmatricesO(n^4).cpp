#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, tSum=0;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            a[i][j] += a[i][j-1];
    for(int j=0; j<n; j++)
        for(int i=0; i<m; i++)
            a[i][j] += a[i-1][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            for(int k=i; k<m; k++)
                for(int l=j; l<n; l++)
                    tSum += a[k][l] - a[i-1][l] - a[k][j-1] + a[i-1][j-1];
    cout<<tSum<<endl;

    return 0;
}
