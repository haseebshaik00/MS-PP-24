#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k, s=0;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    int i=0, j=n-1;
    cin>>k;
    while(i<m && j>=0){
        s = a[i][j];
        if(s == a[i][j]){
            cout<<"Present"<<endl;
            return 0;
        }
        else if(s < a[i][j]) j--;
        else i++;
    }
    cout<<"Absent"<<endl;

    return 0;
}
