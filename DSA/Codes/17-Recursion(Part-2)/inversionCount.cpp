#include<bits/stdc++.h>
using namespace std;

int inversionMerge(int a[], int s, int e){
    int temp[1000]={0};
    int mid = (s+e)/2;
    int i=s, j=mid+1, k=s, c=0;
    while(i<=mid && j<=e){
        if(a[i]<=a[j])
            temp[k++] = a[i++];
        else{
            c += mid+1-i;
            temp[k++] = a[j++];
        }
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=e)
        temp[k++] = a[j++];
    for(int i=s; i<=e; i++)
        a[i] = temp[i];
    return c;
}

int inversionCount(int a[], int s, int e){
    if(s>=e)
        return 0;
    int mid = (s+e)/2;
    int x = inversionCount(a, s, mid);
    int y = inversionCount(a, mid+1, e);
    int z = inversionMerge(a, s, e);
    return x+y+z;
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
    cout<<inversionCount(a, 0, n-1);

    return 0;
}
