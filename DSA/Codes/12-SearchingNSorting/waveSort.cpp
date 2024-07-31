#include<bits/stdc++.h>
using namespace std;

void waveSort(int a[], int n){
    for(int i=0; i<n; i+=2){
        if(i!=0 && a[i]<a[i-1])
            swap(a[i], a[i-1]);
        if(i!=(n-1) && a[i]<a[i+1])
            swap(a[i], a[i+1]);
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
	waveSort(a, n);
	for(auto x:a)
        cout<<x<<" ";

	return 0;
}
