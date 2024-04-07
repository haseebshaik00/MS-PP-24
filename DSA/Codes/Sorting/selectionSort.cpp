#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){

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
    selectionSort(a, n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\n";

    return 0;
}
