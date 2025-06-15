#include<bits/stdc++.h>
#include<iostream>
#include "vector.h"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vectorMock v;
	for(int i=0; i<16; i++)
		v.push_back(i);
	cout<<v.size()<<" "<<v.isEmpty()<<endl;
	for(int i=0; i<12; i++)
		v.pop_back();
	cout<<v.size()<<" "<<v.isEmpty()<<endl;

	return 0;
}