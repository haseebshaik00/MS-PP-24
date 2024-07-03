#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n, cSum=0, tSum=0;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=i; k<m; k++){
                for(int l=j; l<n; l++){
                    for(int p=i; p<=k; p++){
                        for(int q=j; q<=l; q++){
                            cSum += a[p][q];
                            tSum += a[p][q];
                        }
                    }
                    cout<<cSum<<" ";
                }
            }
            cout<<endl;
        }
    }
    cout<<tSum<<endl;

    return 0;
}
