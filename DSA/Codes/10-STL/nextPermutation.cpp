#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		memset(a, n, 0);
		for(int i=0; i<n; i++)
			cin>>a[i];
		next_permutation(a, a+n);
		for(int i=0; i<n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	return 0;
}