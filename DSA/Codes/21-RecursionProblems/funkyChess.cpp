#include<bits/stdc++.h>
using namespace std;

int ans=0;

void knight(int a[][10], int n, int i, int j, int cnt){
	if(i<0 || j<0 || i>=n || j>=n || a[i][j]==0)
		return;
	ans = max(ans, cnt+1);
	a[i][j] = 0;
	knight(a, n, i+1, j+2, cnt+1);
	knight(a, n, i+1, j-2, cnt+1);
	knight(a, n, i-1, j+2, cnt+1);
	knight(a, n, i-1, j-2, cnt+1);
	knight(a, n, i+2, j+1, cnt+1);
	knight(a, n, i+2, j-1, cnt+1);
	knight(a, n, i-2, j+1, cnt+1);
	knight(a, n, i-2, j-1, cnt+1);
	a[i][j] = 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cnt=0;
	cin>>n;
	int a[10][10]={0};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j]) cnt++;
		}
	}
	knight(a, n, 0, 0, 0);
	cout<<cnt-ans;

	return 0;
}