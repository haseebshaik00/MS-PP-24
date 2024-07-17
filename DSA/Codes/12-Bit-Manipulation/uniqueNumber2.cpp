#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int i){
    int a = 1<<i;
    return n&a>0 ? 1:0;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, totalXor, pos=0, d=0, totalXorCopy;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        totalXor ^= a[i];
    totalXorCopy = totalXor;
    while(d==0){
        if(totalXorCopy&1)
            d++;
        totalXorCopy = totalXorCopy>>1;
    }
    for(int i=0; i<n; i++){
        if(getBit(a[i], d))
            pos ^= a[i];
    }
    cout<<pos;
    return 0;
}
