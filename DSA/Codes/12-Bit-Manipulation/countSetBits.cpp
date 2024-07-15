#include<bits/stdc++.h>
using namespace std;

int setBits(int n){
    int ans=0;
    while(n > 0){
        if(n&1) ans++;
        n = n>>1;
    }
    return ans;
}

int setBitsFast(int n){
    int ans = 0;
    while(n>0){
        n = n&(n-1);
        ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<setBits(n)<<endl;
    cout<<setBitsFast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;

    return 0;
}
