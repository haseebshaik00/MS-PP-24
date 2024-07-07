#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s=0;
	cin>>n;
	int a[n];
	memset(a, n, 0);
	int r[n], l[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	r[0] = a[0];
	l[n-1] = a[n-1];
	for(int i=1;i<n;i++)
		r[i] = max(a[i], r[i-1]);
	for(int i=n-2; i>=0; i--)
		l[i] = max(a[i], l[i+1]);
	for(int i=0; i<n; i++)
		s += min(l[i], r[i]) - a[i];
	cout<<s;

	return 0;
}
