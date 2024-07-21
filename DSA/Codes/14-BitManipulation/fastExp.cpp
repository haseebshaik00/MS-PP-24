#include<bits/stdc++.h>
using namespace std;

int powerOpt(int n, int m){
	int ans=1;
	while(m>0){
		if(m&1)
			ans *= n;
		m = m>>1;
		n = n*n;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin>>n>>m;
	cout<<powerOpt(n, m);
	return 0;
}