#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	ll sum, a, ans;
	cin>>t;
	while(t--){
		ll pre[100005]={0};
		pre[0] = 1;
		cin>>n;
		sum=0; ans=0;
		for(int i=0; i<n; i++){
			cin>>a;
			sum += a;
			sum %= n;
			sum = (sum+n)%n;
			pre[sum]++;
		}
		for(int i=0; i<n; i++){
			ll m = pre[i];
			ans += (m*(m-1))/2;
		}
		cout<<ans<<endl;
	}

	return 0;
}
