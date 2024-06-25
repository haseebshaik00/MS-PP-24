#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s=0, smax=INT_MIN;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            s += a[j];
            smax = max(s, smax);
        }
        s=0;
    }
    cout<<smax<<endl;

    return 0;
}
