#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int csum=0, sumMax=INT_MIN;
    for(int i=0; i<n; i++){
        csum += a[i];
        sumMax = max(csum, sumMax);
        csum = csum<0 ? 0 : csum;
    }
    cout<<sumMax<<endl;

    return 0;
}
