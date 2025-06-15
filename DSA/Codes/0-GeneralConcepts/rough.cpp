#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a[] = {1, 2, 3};
    cout << "a       (int*):     " << a << endl; // 0x16bb62a78
    cout << "&a[0]   (int*):     " << &a[0] << endl; // 0x16bb62a78
    cout << "&a      (int (*)[3]): " << &a << endl; // 0x16bb62a78
    cout << "&a + 1  (next array): " << (&a + 1) << endl; // 0x16bb62a84 - similar to whole a + 1
	cout << "&a + 1  (next array): " << (a + 1) << endl; // 0x16b5c6a7c - similar to &a[0] + 1

	return 0;
}
