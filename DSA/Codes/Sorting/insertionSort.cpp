#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
    int j, e;
    for(int i=1; i<n; i++){
        j= i-1;
        e= a[i];
        while(j>=0 && e<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = e;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    insertionSort(a, n);
    for(int i=0;i <n; i++)
        cout<<a[i]<<" ";

    return 0;
}
