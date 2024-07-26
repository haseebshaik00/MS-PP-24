#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(ll n, ll m, ll x, ll y, ll mid){
	if(m + (n-mid)*y >= mid*x) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, x, y, ans=0, mid;
	cin>>n>>m>>x>>y;
	ll i=0, j=n;
	while(i<=j){
		mid = (i+j)/2;
		if(isPossible(n, m, x, y, mid)){
			ans = mid;
			i = mid+1;
		}
		else j = mid-1;
	}
	cout<<ans;

	return 0;
}