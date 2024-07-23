#include<bits/stdc++.h>
using namespace std;

void primeSeive(int a[]){
	a[0] = a[1] = 0;
	a[2] = 1;
	for(int i=3; i<10001; i+=2)
		a[i] = 1;
	for(int i=3; i<10001; i+=2)
		if(a[i])
			for(int j=i*i; j<10001; j+=i)
				a[j] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 10001;
	int a[n]={0}, sumPrime[n]={0};
	primeSeive(a);
	for(int i=2; i<n; i++)
		sumPrime[i] = sumPrime[i-1] + a[i];
    int t, x, y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		cout<<(sumPrime[y]-sumPrime[x-1])<<endl;
	}

	return 0;
}
