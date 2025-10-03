#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void heapify2(vector<int> &v, int idx){
    int l=2*idx, r=2*idx+1, minIdx=idx, lastIdx=v.size()-1;
    if(l<=lastIdx && v[l] < v[minIdx]) minIdx = l;
    if(r<=lastIdx && v[r] < v[minIdx]) minIdx = r;
    if(minIdx != idx){
        swap(v[idx], v[minIdx]);
        heapify2(v, minIdx);
    }
}

void buildHeap(vector<int> &v){
    for(int i=(v.size()-1); i>=1; --i)
        heapify2(v, i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr{2, 8, 0, 1, 4, 7};
    vector<int> v; v.clear();
    v.reserve(arr.size() + 1);
    v.push_back(-1);
    v.insert(v.end(), arr.begin(), arr.end());
    buildHeap(v);
    for(auto &x:v) cout<<x<<" ";

    return 0;
}