#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, denom, setBits, ans=0;
    cin>>n;
    int prime[] = {2, 3, 5, 7, 11, 12, 17, 19};
    int l = (1<<8)-1;
    for(int i=1; i<=l; i++){ //subsets
        denom=1;
        setBits = __builtin_popcount(i);
        for(int j=0; j<=7; j++){ // iterate over prime array
            if(i & (1<<j)){
                denom *= prime[j];
            }
        }
        if(setBits&1) ans += n/denom;
        else ans -= n/denom;
    }
    cout<<ans<<endl;

    return 0;
}
