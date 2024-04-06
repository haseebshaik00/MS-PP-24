#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
    int l;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                l = a[i];
                a[i]=a[j];
                a[j]=l;
                // swap(a[i], a[j]);
            }
        }
    }
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
    bubbleSort(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
