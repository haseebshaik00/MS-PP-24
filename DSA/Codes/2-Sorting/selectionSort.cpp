#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
    int min_index;
    for(int i=0;i<n-1;i++){
        min_index=i;
        for(int j=i+1; j<n; j++){
            if(a[min_index] > a[j])
                min_index = j;
        }
        swap(a[i], a[min_index]);
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
    selectionSort(a, n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
