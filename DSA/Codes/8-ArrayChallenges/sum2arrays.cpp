#include<bits/stdc++.h>
using namespace std;

void findSum(int a[], int b[], int n, int m){
	int c = 0, csum=0, j=m-1;
	for(int i=n-1; i>=0; i--){ 
		if(j>=0){
			csum = a[i] + b[j] + c;
			j--;
		}
		else csum = a[i] + c;
		c = csum / 10;
		a[i] = csum%10;
	}
	if(c) cout<<c<<", ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<", ";
	cout<<"END";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin>>n;
	int a[n];
	memset(a, n, 0);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>m;
	int b[m];
	memset(b, m, 0);
	for(int i=0; i<m; i++)
		cin>>b[i];
	(n>m) ? findSum(a, b, n, m) : findSum(b, a, m, n);

	return 0;
}