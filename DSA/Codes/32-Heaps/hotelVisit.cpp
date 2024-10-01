#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll q, k, d, a, b;
	priority_queue<ll> pq;
	cin>>q>>k;
	while(q--){
		cin>>d;
		if(d==1){
			cin>>a>>b;
			ll c = pow(a, 2) + pow(b, 2);
			if(pq.size() >= k){
				if(c < pq.top()){
					pq.pop();
					pq.push(c);
				}
			}
			else
				pq.push(c);
		}
		else{
			cout<<pq.top()<<endl;
		}
	}	
	
	return 0;
}