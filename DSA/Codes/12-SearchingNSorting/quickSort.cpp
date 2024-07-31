#include<bits/stdc++.h>
using namespace std;

int partitionIt(int a[], int s, int e){
    int p=a[e], i=s-1;
    for(int j=s; j<e; j++){
        if(a[j] <= p)
            swap(a[++i], a[j]);
    }
    swap(a[i+1], a[e]);
    return i+1;
}

void quickSort(int a[], int s, int e){
    if(s>=e)
        return;
    int p = partitionIt(a, s, e);
    quickSort(a, s, p-1);
    quickSort(a, p+1, e);
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
    quickSort(a, 0, n-1);
    for(auto x:a)
        cout<<x<<" ";

    return 0;
}
