#include<bits/stdc++.h>
using namespace std;

void primeSeive(bool a[], int n){
    a[0] = a[1] = false;
    a[2] = true;
    for(int i=3; i<=n; i+=2)
        a[i] = true;
    for(int i=3; i<=n; i+=2)
        if(a[i])
            for(int j=i*i; j<=n; j+=(2*i))
                a[j] = false;
}

void factors(vector<int> primes, int n){
    int l=primes.size(), c, ans=1;
    for(int i=0; i<l; i++){
        c=0;
        while(n%primes[i] == 0){
            c++;
            n /= primes[i];
        }
        if(c) ans *= (c+1);
    }
    if(n!=1) ans *=2;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    bool a[n]={false};
    primeSeive(a, n);
    vector<int> primes;
    for(int i=2; i<=n; i++)
        if(a[i]) primes.push_back(i);
    factors(primes, n);

    return 0;
}
