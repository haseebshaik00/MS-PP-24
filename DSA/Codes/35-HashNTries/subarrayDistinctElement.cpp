#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, j=0, ans=0;
	cin>>n;
	int a[n]={0};
	for(int i=0; i<n; i++)	
		cin>>a[i];
	unordered_map<int, int> m;
	for(int i=0; i<n; i++){
		while(j<n && m.find(a[j]) == m.end()){
			m[a[j]]++;
			j++;
		}
		ans += (((j-i) * (j-i+1))/2) % 1000000007;
		ans = ans % 1000000007;
		m.erase(a[i]);
	}
	cout<<(ans%1000000007);

	return 0;
}