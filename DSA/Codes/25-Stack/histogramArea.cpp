#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	ll a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	stack<int> s;
	ll currentArea, top, maxArea=0, i=0;
	while(i<n){
		if(s.empty() || a[i] >= a[s.top()])
			s.push(i++);
		else{
			top = s.top();
			s.pop();
			currentArea = a[top] * (s.empty() ? i : (i-s.top()-1));
			maxArea = max(currentArea, maxArea);
		}
	}
	while(!s.empty()){
			top = s.top();
			s.pop();
			currentArea = a[top] * (s.empty() ? i : (i-s.top()-1));
			maxArea = max(currentArea, maxArea);
	}
	cout<<maxArea;

    return 0;
}
