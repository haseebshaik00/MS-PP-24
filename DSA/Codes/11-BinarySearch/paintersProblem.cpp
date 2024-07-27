#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(ll a[], ll n, ll k, ll t, ll mid){
	ll painted = 0, painter=1;
	for(ll i=0; i<n; i++){
		if(painted + a[i]*t > mid){
			painter++;
			painted = a[i]*t;
			if(painter > k)
				return false;
		}
		else painted += a[i]*t;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k, t, i=INT_MIN, j, mid, ans=0;
	cin>>n>>k>>t;
	ll a[n];
	memset(a, 0, n);
	for(ll k=0; k<n; k++){
		cin>>a[k];
		i = max(i, a[k]);
	}
	i = i*t;
	j = accumulate(a, a+n, 0) * t;
	while(i<=j){
		mid = (i+j)/2;
		if(isPossible(a, n, k, t, mid)){
			ans = mid;
			j = mid-1;
		}
		else i = mid+1;
	}
	cout<<ans%10000003;

	return 0;
}