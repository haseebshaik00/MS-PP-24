#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPoss(int m, int n, int mid){
  if(pow(mid, n) <= m)
    return true;
  return false;
}

int NthRoot(int n, int m) {
  int i=0, j=m, ans=-1;
  while(i<=j){
    int mid = (i+j)/2;
    if(isPoss(m, n, mid)){
      ans = mid;
      i=mid+1;
    }
    else j = mid-1;
  }
  return (pow(ans,n) == m) ? ans : -1;
}

bool isPossible(ll n, ll k, ll mid){
	if(pow(mid, k) <= n) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll i=0, j=n, mid, ans=0;
		while(i<=j){
			mid = (i+j)/2;
			if(isPossible(n, k, mid)){
				ans = mid;
				i = mid+1;
			}
			else j=mid-1;
		}
		cout<<ans<<endl;
	}

	return 0;
}