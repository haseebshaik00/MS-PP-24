#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* ---- Heap ----
- Complete binary tree (all levels full except maybe the last, filled from left to right)
- Index formulas (1-based):
    parent(i) = i/2
    left(i) child = 2*i
    right(i) child = 2*i+1

- Min-heap: Every parent <= children &
- Max-heap: Every parent >= children

- Insert(push): ------ [Bottom Up Approach]
Add element at the end, then sift up / percolate up until heap property is restored.
Time complexity: Worst: O(log n) (height of tree)

- Get Top (peek): Return root (v[1] in array)
Time complexity: O(1)

- Delete Top (pop) ------ [Top Down Approach]
Swap root with last element, remove last, then sift down / percolate down / heapify down.
Time complexity: Worst: O(log n)

- Heapify (local repair) ------ [Top Down Approach]
Given a node at index i, fix heap property by pushing it down.
heapify(i) = the procedure that fixes the heap property at a node i, assuming both its left and right subtrees are already valid heaps.
Often called MAX-HEAPIFY / MIN-HEAPIFY (CLRS).
Time complexity: O(log n)

- Build Heap (make_heap)
Turn an arbitrary array into a heap.
Method (Floyd’s algorithm): Run heapify from the last non-leaf to root.
Time complexity: O(n) (not O(n log n) because work halves each level).

- Heap Sort
Build heap O(n), then extract max/min repeatedly (n times).
Time complexity: O(n log n)
Space: in-place O(1) (array-based)

*/

class Heap{
public:

    bool minHeap;
    vector<int> v;

    bool compare(int a, int b){
        if(minHeap) return (a<b);
        return (a>b);
    }

    Heap(bool minMax=true, int defaultSize=10){
        minHeap = minMax;
        v.reserve(defaultSize+1);
        v.clear();
        v.push_back(-1);
    }

    void heapify(int idx){
        int lc = 2*idx, rc = 2*idx+1, extremeIdx = idx, lastIdx = v.size()-1;
        if(lc <= lastIdx && compare(v[lc], v[extremeIdx])) extremeIdx = lc;
        if(rc <= lastIdx && compare(v[rc], v[extremeIdx])) extremeIdx = rc;
        if(extremeIdx != idx){
            swap(v[extremeIdx], v[idx]);
            heapify(extremeIdx);
        }
    }

    void push(int d){ // also called as sift up and percolate up
        v.push_back(d);
        if(size() == 1) return;
        for(int idx = v.size()-1; 
            idx>1 && compare(v[idx], v[idx/2]); 
            idx = idx/2)
            swap(v[idx], v[idx/2]);
    }

    void pop(){ // also called as sift down and percolate down
        if(isEmpty()) return;
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        if(!isEmpty()) heapify(1);
    }

    int get() const {
        return v[1];
    }

    int size() const {
        return v.size()-1;
    }

    bool isEmpty() const {
        return v.size() == 1;
    }

    void print(){
        if(isEmpty()) return;
        for (size_t i = 1; i < v.size(); ++i) cout << v[i] << ' ';
        cout<<endl;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     // Min-heap
    Heap minh(true);
    for (int x : {5, 3, 8, 1, 7, 2}) minh.push(x);
    cout << "Min-heap after pushes: "; minh.print();     // expect root = 1

    cout << "Peek min: " << minh.get() << "\n";          // 1
    while (!minh.isEmpty()) {
        cout << "Pop " << minh.get() << " -> ";
        minh.pop();
        minh.print();
    }

    return 0;
}