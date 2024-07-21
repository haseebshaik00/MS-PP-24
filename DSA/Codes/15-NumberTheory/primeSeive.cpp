#include<bits/stdc++.h>
using namespace std;

void primeSeive(int a[], int n){
    a[0] = a[1] = 0;
    a[2] = 1;
    for(int i=3; i<=n; i+=2)
        a[i] = 1;
    for(int i=3; i<=n; i+=2)
        if(a[i])
            for(int j=i*i; j<=n; j+=2*i)
                a[j] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n+1]={0};
    memset(a, n+1, 0);
    primeSeive(a, n);
    for(int i=0; i<=n; i++){
        if(a[i]) cout<<i<<" ";
    }

    return 0;
}
