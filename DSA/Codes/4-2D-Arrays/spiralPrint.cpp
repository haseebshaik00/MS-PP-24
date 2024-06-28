#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    int sr=0, er=m-1, sc=0, ec= n-1;
    while( sr<=er && sc<=ec ){
        for(int i=sc; i<=ec; i++)
            cout<<a[sr][i]<<" ";
        sr++;
        for(int i=sr; i<=er; i++)
            cout<<a[i][ec]<<" ";
        ec--;
        if(sr<=er){
            for(int i=ec; i>=sc; i--)
                cout<<a[er][i]<<" ";
            er--;
        }
        if(sc<=ec){
            for(int i=er; i>=sr; i--)
                cout<<a[i][sc]<<" ";
            sc++;
        }
    }

    return 0;
}
