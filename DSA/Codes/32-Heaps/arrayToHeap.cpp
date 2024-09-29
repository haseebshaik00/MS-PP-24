#include<bits/stdc++.h>
using namespace std;

// O(n logn) approach
void makeHeap(vector<int> &v){
    for(int i=2; i<v.size(); i++){
        int child = i, parent = i/2;
        while(child > 1 && (v[child] > v[parent])){
            swap(v[child], v[parent]);
            child = parent;
            parent /= 2;
        }
    }
}

void heapify(vector<int> &v, int idx){
    int l = idx*2, r = (idx*2)+1, maxIdx = idx, n = v.size();
    if(l<n && (v[l] > v[maxIdx])) maxIdx = l;
    if(r<n && (v[r] > v[maxIdx])) maxIdx = r;
    if(maxIdx != idx){
        swap(v[maxIdx], v[idx]);
        heapify(v, maxIdx);
    }
}

void makeHeapFast(vector<int> &v){
    int n = v.size()-1;
    for(int i=n/2; i>=1; i--)
        heapify(v, i);
}

void heapifySort(vector<int> &v, int idx, int n){
    int l = idx*2, r = idx*2+1, maxIdx = idx;
    if(l<n && (v[l] > v[maxIdx])) maxIdx = l;
    if(r<n && (v[r] > v[maxIdx])) maxIdx = r;
    if(idx != maxIdx){
        swap(v[idx], v[maxIdx]);
        heapifySort(v, maxIdx, n);
    }
}

void heapSort(vector<int> &v){
    makeHeapFast(v);
    int n = v.size()-1;
    while(n>1){
        swap(v[1], v[n]);
        n--;
        heapifySort(v, 1, n);
    }
}

void print(vector<int> v){
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    vector<int> v1{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    vector<int> v2{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    makeHeap(v);
    makeHeapFast(v1);
    print(v);
    print(v1);
    heapSort(v2);
    print(v2);

    return 0;
}
