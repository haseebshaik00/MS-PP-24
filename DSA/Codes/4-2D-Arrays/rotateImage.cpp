#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // square matrix
    int m,n;
    cin>>m>>n;
    int a[10][10];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    // reverse
    for(int i=0; i<m; i++)
        reverse(a[i], a[i]+n);
    // transpose
    for(int i=0; i<m; i++)
        for(int j=0; j<i; j++)
            swap(a[i][j], a[j][i]);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
