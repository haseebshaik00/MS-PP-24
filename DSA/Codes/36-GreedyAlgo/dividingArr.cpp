#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a.begin(), a.end());
		long long int maxi = 0, mini =0;
		for(int i=0; i<(n/2);i++){
			maxi += abs(a[n - 1 - i] - a[i]);;
			mini += abs(a[(2 * i) + 1] - a[2 * i]);
		}
		cout<<mini<<" "<<maxi<<endl;
	}

    return 0;
}