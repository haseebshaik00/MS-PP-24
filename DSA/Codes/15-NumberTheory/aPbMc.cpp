#include<bits/stdc++.h>
using namespace std;
#define ll long long

int aPbMc(int a, int b, int c){
    int ans=1;
    while(b>0){
        if(b%2 == 1)
            ans = (ans*a)%c;
        a = (a*a)%c;
        b /= 2;
    }
    return ans;
}

int main() {
	int a, b, c;
	ll ans=1;
	cin>>a>>b>>c;
	cout<<aPbMc(a, b, c)<<endl;
	while(b>0){
		ans *= a;
		ans %= c;
		b--;
	}
	cout<<ans%c<<endl;
	return 0;
}
