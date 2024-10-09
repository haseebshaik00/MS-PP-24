#include <bits/stdc++.h>
using namespace std;

// the two sticks in a pair of chopsticks need not be of the same length
// A stick can't be part of more than one pair of chopsticks

int main() {
	int n, d;
	cin>>n>>d;
	int a[n] = {0};
	for(int i=0; i<n; i++)
	    cin>>a[i];
	sort(a, a+n);
	int i=0, ans=0;
	while(i<n-1){
	    if((a[i+1]-a[i]) <= d){
	        ans++;
	        i += 2;
	    }
	    else i++;
	}
	cout<<ans;
	
    return 0;   
}
