#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin>>n>>c;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int i=0, j=a[n-1];

	return 0;
}
