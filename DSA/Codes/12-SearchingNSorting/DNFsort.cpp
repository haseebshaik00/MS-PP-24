#include<bits/stdc++.h>
using namespace std;

void dnfSort(int a[], int n){
	int l=0, m=0, h=n-1;
	while(m<h){
		if(a[m] == 0){
			swap(a[l], a[m]);
			l++; m++;
		}
		else if(a[m] == 1)
			m++;
		else{
			swap(a[h], a[m]);
			h--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	dnfSort(a, n);
	for(auto x:a)
		cout<<x<<endl;

	return 0;
}
