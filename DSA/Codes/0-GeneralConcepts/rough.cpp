#include<bits/stdc++.h>
using namespace std;

void iSort(int a[], int n){
    int j,e;
    for(int i=1; i<n; i++){
        e = a[i];
        j = i-1;
        while(j>=0 && a[j]>e){
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
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    iSort(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
