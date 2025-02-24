#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int bSearch(int a[], int n, int key){
    int i=0, j=n-1, mid;
    while(i<=j){
        mid = (i+j)/2;
        if(a[mid] == key) return mid;
        else if(a[mid] < key) i=mid+1;
        else j=mid-1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, key;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>key;
    cout<<"Position = "<<bSearch(a, n, key)<<endl;

    return 0;
}
