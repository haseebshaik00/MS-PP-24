#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n, d;
    cin>>n;
    int ans=0;
    for(int i=0; i<n; i++){
        cin>>d;
        ans ^= d;
    }
    cout<<ans;

    return 0;
}
