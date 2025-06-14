#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool comp(int a, int b){
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a[5] {3,4,2,1,5};
	sort(a, a+5, [](int a, int b) { return a > b; });
	for(int i=0; i<5; i++)
		cout<<a[i]<<" ";

	return 0;
}