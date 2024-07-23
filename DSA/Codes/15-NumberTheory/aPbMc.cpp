#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int a, b, c;
	ll ans=1;
	cin>>a>>b>>c;
	while(b>0){
		ans *= a;
		ans %= c;
		b--;
	}
	cout<<ans;
	return 0;
}
