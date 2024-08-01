#include<bits/stdc++.h>
using namespace std;

int ladderFunc(int n, int k){
    if(n==0) return 1;
    if(n<0) return 0;
    int ans=0;
    for(int i=1; i<=k; i++)
        ans += ladderFunc(n-i, k);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    cout<<ladderFunc(n, k)<<endl;

    return 0;
}
