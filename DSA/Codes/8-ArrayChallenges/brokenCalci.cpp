#include<bits/stdc++.h>
using namespace std;

int mul(int x, int n, int a[]){
	int carr=0, cSum=0;
	for(int i=0; i<n; i++){
		cSum = x * a[i] + carr;
		a[i] = cSum%10;
		carr = cSum/10;
	}
	while(carr){
		a[n] = carr%10;
		n++;
		carr /= 10;
	}
	return n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, size=1;
	cin>>n;
	int a[1000];
	memset(a, 1000, 0);
	a[0] = 1;
	for(int i=2; i<=n; i++)
		size = mul(i, size, a);
	for(int i=size-1; i>=0; i--)
		cout<<a[i];

	return 0;
}