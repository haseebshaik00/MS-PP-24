#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool compare(int a, int b){
    return a<b; // decreasing
}

void bubbleSortComp(int a[], int n, bool (&comp)(int a, int b)){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1-i; j++)
            if(comp(a[j], a[j+1]))
                swap(a[j], a[j+1]);
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
    bubbleSortComp(a, n, compare);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;

}