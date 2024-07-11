#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char a[] = "geeks";
	char *p = "geeks";
    a[1] = 'a';
	cout<<a<<" "<<*p<<" "<<sizeof(*p);

	// int *c = 2; -> not allowed

	return 0;
}
