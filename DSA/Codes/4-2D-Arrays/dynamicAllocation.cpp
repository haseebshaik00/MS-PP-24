#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;
    int **a = new int*[m]; // pointer array of pointers
    for(int i=0; i<m; i++)
        a[i] = new int[n]; // assign each row with n size columns
    for(int i=0; i<m; i++)
        for(int j=0;j<n; j++)
            cin>>a[i][j];
    for(int i=0; i<m; i++)
        for(int j=0;j<n; j++)
            cout<<a[i][j]<<" ";
    for(int i=0; i<m; i++)
        delete []a[i]; // delete each row

    delete []a; // delete pointer as a whole
    a = NULL; // point a to NULL to avoid memory leak

    return 0;
}
