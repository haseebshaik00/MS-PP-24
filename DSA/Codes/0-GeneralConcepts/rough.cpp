#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	int left=0, right=0, sumMax=INT_MIN;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int s=0;
			for(int k=i; k<=j; k++)
				s+=a[k];
			if(s>=sumMax){
				left=i; right=j;
				sumMax = s;
			}
		}
	}
	cout<<left<<" "<<right<<" "<<sumMax;

	return 0;
}