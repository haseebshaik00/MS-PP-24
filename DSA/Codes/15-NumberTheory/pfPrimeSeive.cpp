#include<bits/stdc++.h>
using namespace std;

void primeSeive(bool a[], int n){
    a[0] = a[1] = false;
    a[2] = true;
    for(int i=3; i<=n; i+=2)
        a[i] = true;
    for(int i=3; i<=n; i+=2)
        if(a[i])
            for(int j=i*i; i<=n; j+=(2*i))
                a[i] = false;
}

void factors(vector<int> primes, vector<pair<int, int>> &factor, int n){
    int l=primes.size(), c;
    for(int i=0; i<=l & (primes[i]*primes[i])<=n; i++){
        c=0;
        while(n%primes[i] == 0){
            c++;
            n /= primes[i];
        }
        factor.push_back(make_pair(primes[i], c));
    }
    if(n!=1) factor.push_back(make_pair(n, 1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m=100;
    cin>>n;
    bool prime[m]={false};
    vector<int> primes;
    vector<pair<int, int>> factor;
    primeSeive(prime, m);
    for(int i=2; i<=n; i++)
        if(prime[i]) primes.push_back(i);
    factors(primes, factor, n);
    for(auto x:factor)
        cout<<x.first<<" "<<x.second<<endl;
    return 0;
}
