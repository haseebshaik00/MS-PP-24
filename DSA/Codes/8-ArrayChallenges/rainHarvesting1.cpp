#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, n, 0);
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1, lmax=0, rmax=0, s=0;
	while(l <= r){
		if(a[l] <= a[r]){
			if(a[l] > lmax) lmax = a[l];
			else s += lmax - a[l];
			l++;
		}
		else{
			if(a[r] > rmax) rmax = a[r];
			else s += rmax - a[r];
			r--;
		}
	}
	cout<<s;

	return 0;
}
