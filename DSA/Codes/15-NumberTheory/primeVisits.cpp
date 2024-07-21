#include<bits/stdc++.h>
using namespace std;

void primeSeive(long long int a[], long long int n){
	a[0] = a[1] = 0;
	a[2] = 1;
	for(long long int i=3; i<=n; i+=2)
		a[i] = 1;
	for(long long int i=3; i<=n; i+=2)
		if(a[i])
			for(long long int j=i*i; j<=n; j+=(2*i))
				a[j] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n = 1000001;
	long long int a[1000001], sumPrime[1000001];
	int t, x, y;
	cin>>t;
	memset(a, n, 0);
	primeSeive(a, n);
	for(long long int i=0; i<n; i++)
		sumPrime[i] = sumPrime[i-1] + a[i];
	while(t--){
		cin>>x>>y;
		cout<<(sumPrime[y]-sumPrime[x-1])<<endl;
	}

	return 0;
}
