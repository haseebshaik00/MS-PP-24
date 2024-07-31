#include<bits/stdc++.h>
using namespace std;

void mergeThem(int a[], int s, int e){
    int temp[100] = {0};
    int mid = (s+e)/2;
    int i=s, j=mid+1, k=s;
    while(i<=mid && j<=e){
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i<=mid) temp[k++] = a[i++];
    while(j<=e) temp[k++] = a[j++];
    for(int i=s; i<=e; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int s, int e){
    if(s>=e) return;
    int mid = (s+e)/2;
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);
    mergeThem(a, s, e);
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
    mergeSort(a, 0, n-1);
    for(auto x:a)
        cout<<x<<" ";

    return 0;
}
