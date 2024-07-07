#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n, tMax=INT_MIN;
		cin>>n;
		int a[n], inc[n], dec[n];
		inc[0] = 1; dec[n-1] = 1;
		memset(a, n, 0);
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=1; i<n; i++){
			if(a[i] >= a[i-1]) inc[i] = inc[i-1] + 1;
			else inc[i] = 1;
		}
		for(int j=n-2; j>=0; j--){
			if(a[j] >= a[j+1]) dec[j] = dec[j+1] + 1;
			else dec[j] = 1;
		}
		for(int i=0; i<n; i++)
			tMax = max(dec[i] + inc[i] - 1, tMax);
 		cout<<tMax<<endl;
	}

	return 0;
}
