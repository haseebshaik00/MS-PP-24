#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll tile(int n, int m){
	if(n<m) return 1;
	if(n==m) return 2;
 	return tile(n-1, m) + tile(n-m, m); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		cout<<(tile(n, m) % 1000000007)<<endl;
	}

	return 0;
}
