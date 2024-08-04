#include<bits/stdc++.h>
using namespace std;

int flag = 0;

void sub(int a[], int b[], int n, int i, int j){
	if(i==n){
		int s=0;
		if(j==0) return;
		for(int k=0; k<j; k++)
			s += b[k];
		if(s==0 && flag==0){
			cout<<"Yes"<<endl;
			flag=1;
		}
		return;
	}
	b[j] = a[i];
	sub(a, b, n, i+1, j+1);
	sub(a, b, n, i+1, j);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n], b[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		flag=0;
		sub(a, b, n, 0, 0);
		if(!flag) cout<<"No"<<endl;
	}

	return 0;
}
