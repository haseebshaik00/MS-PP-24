#include<bits/stdc++.h>
using namespace std;
#define m 10001
bool primes[m];

void primeSeive(int n){
    memset(primes, false, m);
    primes[0] = primes[1] = false;
    primes[2] = true;
    for(int i=3; i<m; i+=2)
        primes[i] = true;
    for(int i=3; i<m; i+=2){
        if(primes[i]){
            for(int j=i*i; j<m; j+=(2*i))
                primes[j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // prints primes nos from 1->n
    int n;
    cin>>n;
    primeSeive(n);
    for(int i=0; i<n; i++)
        if(primes[i]) cout<<i<<" ";

    return 0;
}
