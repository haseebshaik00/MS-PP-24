#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i< m; i++)
        for(int j=0; j< n; j++)
            cin>>a[i][j];
    for(int i=0; i< m; i++){
        for(int j=0; j< n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            for(int j=0; j<m; j++){
                cout<<a[j][i]<<" ";
            }
        }
        else{
            for(int j=m-1; j>=0; j--){
                cout<<a[j][i]<<" ";
            }
        }
    }

    return 0;
}
