#include<bits/stdc++.h>
using namespace std;

int optGame(int a[], int i, int j){
	if(i>j)
		return 0;
	int l = a[i] + min(optGame(a, i+2, j), optGame(a, i+1, j-1));
	int r = a[j] + min(optGame(a, i, j-2), optGame(a, i+1, j-1));
	return max(l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<optGame(a, 0, n-1);

	return 0;
}
