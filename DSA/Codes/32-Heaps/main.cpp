#include<bits/stdc++.h>
using namespace std;

class Heap{
public:
    bool minHeap;
    vector<int> v;

    Heap(int defaultSize=10, bool minMax=true){
        minHeap = minMax;
        v.reserve(defaultSize+1);
        v.push_back(-1);
    }

    bool compare(int a, int b){
        if(minHeap) return (a < b);
        return (a > b);
    }

    void push(int d){
        v.push_back(d);
        int child = v.size()-1;
        int parent = child/2;
        while(child > 1 && compare(v[child], v[parent])){
            swap(v[child], v[parent]);
            child = parent;
            parent = child/2;
        }
    }

    void heapify(int idx){
        int left = 2*idx;
        int right = left + 1, minIdx = idx, n = v.size();
        if(left < n && compare(v[left], v[minIdx])) minIdx = left;
        if(right < n && compare(v[right], v[minIdx])) minIdx = right;
        if(minIdx != idx){
            swap(v[minIdx], v[idx]);
            heapify(minIdx);
        }
    }

    void pop(){
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }

    int get(){
        return v[1];
    }

    bool isEmpty(){
        return v.size() == 1;
    }

    void print(){
        for(auto x : v)
            cout<<x<<" ";
        cout<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Heap h;
    for(int i=1; i<12; i++)
        h.push(i);
    h.pop();
    h.push(7);
    h.pop();
    while(!h.isEmpty()){
        cout<<h.get()<<" ";
        h.pop();
    }

    return 0;
}
