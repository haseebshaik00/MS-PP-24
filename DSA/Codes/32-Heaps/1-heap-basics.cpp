#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class minHeap{
public:
    bool heapMin;
    vector<int> v;

    minHeap(bool heapMin=true, int defaultSize=10){
        this->heapMin = heapMin;
        v.reserve(defaultSize+1);
        v.clear(); v.push_back(-1);
    }

    bool compare(int a, int b) const{
        return heapMin ? (a < b) : (a > b);
    }

    void heapify(int idx){
        int l=2*idx, r=2*idx+1, minIdx=idx, lastIdx=size();
        if(l <= lastIdx && compare(v[l], v[minIdx])) minIdx = l;
        if(r <= lastIdx && compare(v[r], v[minIdx])) minIdx = r;
        if(minIdx != idx){
            swap(v[minIdx], v[idx]);
            heapify(minIdx);
        }
    }

    void push(int d){
        v.push_back(d);
        for(int idx=size(); idx>1 && compare(v[idx], v[idx/2]); idx=idx/2)
            swap(v[idx], v[idx/2]);
    }

    void pop(){
        if(empty()) return;
        swap(v[1], v[size()]); 
        v.pop_back();
        if(!empty()) heapify(1);
    }

    int get() const {return empty() ? -1 : v[1];} //top()
    int size()  const {return (int)v.size() - 1;}
    bool empty() const {return size() == 0;}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // push/pop = O(log n), get = O(1), heapify = O(log n)
    // same as: minHeap mh(true);
    minHeap mh;                   
    // Or declare a MAX-heap 
    minHeap mx(false);
    // Test the min-heap
    vector<int> a{5, 1, 3, 4, 2, 7};
    for (int x : a) mh.push(x);
    cout << "Min-heap pops: ";
    while (!mh.empty()) {
        cout << mh.get() << ' ';
        mh.pop();
    }
    cout << '\n';
    // Test the max-heap
    for (int x : a) mx.push(x);
    cout << "Max-heap pops: ";
    while (!mx.empty()) {
        cout << mx.get() << ' ';
        mx.pop();
    }
    cout << '\n';
    return 0;
}