#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	int i = 0;
    int j = n - 1;
    while (i < j) {
        int mid = (i+j)/ 2;
        if (a[mid] < a[j])
            j = mid;
        else
            i = mid+1;
    }
    cout<<i; // cout<<j; when i=j we get our answer

	return 0;
}
