#include<bits/stdc++.h>
using namespace std;

// GFG Soln - works with -ve nos as well!
int getSingle(vector<int> &arr) {
	int c[64] = {0}; long long ans = 0;
	for (int x : arr)
		for (int i = 0; i < 64; i++)
			if (x & (1LL << i)) c[i]++;
	for (int i = 0; i < 64; i++)
		if (c[i] % 3) ans |= (1LL << i);
	return static_cast<int>(ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, p=1, ans=0;
	cin>>n;
	int c[64]= {0};
	for(int i=0; i<n; i++){
		cin>>d;
		int j=0;
		while(d>0){
			c[j] += (d & 1);
			d = d>>1; 
			j++;
		}
	}
	for(int i=0; i<64; i++){
		if(c[i]%3) ans += (p*(c[i]%3));
		p = p<<1;
	}
	cout<<ans;

	return 0;
}