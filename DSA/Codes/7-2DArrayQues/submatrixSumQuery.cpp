#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;
    int m, n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    // take care - dont add garbage values a[-1][j] or a[i][-1]
    for(int i=0; i<m; i++)
        for(int j=1; j<n; j++)
            a[i][j] += a[i][j-1];
    for(int j=0; j<n; j++)
        for(int i=1; i<m; i++)
            a[i][j] += a[i-1][j];
    while(k){
        int p,q,r,s;
        cin>>p>>q>>r>>s;
        int c = a[r][s];
        if(q>0) c -= a[r][q-1];
        if(p>0) c -= a[p-1][s];
        if(p>0 && q>0) c += a[p-1][q-1];
        cout<<c<<endl;
    }

    return 0;
}
