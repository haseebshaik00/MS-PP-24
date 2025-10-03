#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void heapify3(vector<int> &v, int idx, int n){
    int l=2*idx, r=2*idx+1, minIdx=idx;
    if(l<=n && v[l] < v[minIdx]) minIdx = l;
    if(r<=n && v[r] < v[minIdx]) minIdx = r;
    if(idx != minIdx){
        swap(v[minIdx], v[idx]);
        heapify3(v, minIdx, n);
    }
}

void buildHeap(vector<int> &v, int n){
    for(int i=n/2; i>=1; --i)
        heapify3(v, i, n);
}

void heapSort(vector<int> &v){
    int n = v.size() - 1;
    buildHeap(v, n);
    while(n > 1){
        swap(v[1], v[n]);
        heapify3(v, 1, --n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr{2, 8, 0, 1, 4, 7};
    arr.insert(arr.begin(), -1);
    heapSort(arr);
    for(auto &x:arr) cout<<x<<" ";

    return 0;
}