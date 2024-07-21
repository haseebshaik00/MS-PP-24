#include<bits/stdc++.h>
using namespace std;

int decToBinary(int n){
    int ans=0, p=1, d=0;
    while(n>0){
        d = n&1;
        ans += d*p;
        p*=10;
        n = n>>1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<decToBinary(n)<<endl;

    return 0;
}
