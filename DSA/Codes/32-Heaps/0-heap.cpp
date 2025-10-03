#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* ---- Heap ----
- Complete binary tree (all levels full except maybe the last, filled from left to right)
- Index formulas (1-based array):
    parent(i) = i/2
    left(i) child = 2*i
    right(i) child = 2*i+1

- Min-heap: Every parent <= children &
- Max-heap: Every parent >= children

- Get Top (peek): Return root (v[1] in array)
Time complexity: O(1)

- Insert(push): ------ [Bottom Up Approach] -------- O(log n)
Add element at the end, then sift up / percolate up until heap property is restored.
Time complexity: Worst: O(log n) (height of tree)

- Delete Top (pop) ------ [Top Down Approach] ------- O(log n)
Swap root with last element, remove last, then sift down / percolate down / heapify down.
Time complexity: Worst: O(log n)

- Heapify (local repair) ------ [Top Down Approach] -------- O(log n)
Given a node at index i, fix heap property by pushing it down.
heapify(i) = the procedure that fixes the heap property at a node i, assuming both its left and right subtrees are already valid heaps.
Often called MAX-HEAPIFY / MIN-HEAPIFY (CLRS).
Time complexity: O(log n)

- Build Heap (make_heap) inplace ------ Floyd's Algo ------ [Bottom Up Approach] -------- O(n)
Turn an arbitrary array into a heap.
Method (Floyd’s algorithm): Run heapify from the last non-leaf to root.
Time complexity: O(n) (not O(n log n) because work halves each level).
*Why it’s O(n) (intuition)*: Only nodes near the top can sift down many levels, but there are few of them; nodes near the bottom are many, 
but each can move at most 1–2 steps. Summing the possible work across levels gives a geometric series bounded by a constant times n, hence linear time.

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

    Heap(bool minHeap=true, int defaultSize=10){
        this->minHeap = minHeap;
        v.reserve(defaultSize+1);
        v.clear();
        v.push_back(-1);
    }

    void heapify(int idx){ // O(log n)
        int lc = 2*idx, rc = 2*idx+1, extremeIdx = idx, lastIdx = v.size()-1;
        if(lc <= lastIdx && compare(v[lc], v[extremeIdx])) extremeIdx = lc;
        if(rc <= lastIdx && compare(v[rc], v[extremeIdx])) extremeIdx = rc;
        if(extremeIdx != idx){
            swap(v[extremeIdx], v[idx]);
            heapify(extremeIdx);
        }
    }

    void push(int d){ // also called as sift up and percolate up - O(log n)
        v.push_back(d);
        if(size() == 1) return;
        for(int idx = v.size()-1; idx>1 && compare(v[idx], v[idx/2]); idx = idx/2)
            swap(v[idx], v[idx/2]);
    }

    void pop(){ // also called as sift down and percolate down - O(log n)
        if(isEmpty()) return;
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        if(!isEmpty()) heapify(1);
    }

    int get() const {return v[1];}
    int size() const {return v.size()-1;}
    bool isEmpty() const {return v.size() == 1;}

    void print(){
        if(isEmpty()) return;
        for (size_t i = 1; i < v.size(); ++i) cout << v[i] << ' ';
        cout<<endl;
    }
    
    void buildHeap(const vector<int>& arr) {
        v.clear(); v.push_back(-1);
        v.insert(v.end(), arr.begin(), arr.end());
        for (int i=size()/2; i >= 1; --i)
            heapify(i);
    }
};


//  Build Heap from an array - Floyd's Algo - O(n)--------------
void heapify(vector<int>& v, int idx){ // O(log n)
    int lc = 2*idx, rc = 2*idx + 1, minIdx = idx, lastIdx = v.size()-1;
    if(lc <= lastIdx && v[lc] < v[minIdx]) minIdx = lc;
    if(rc <= lastIdx && v[rc] < v[minIdx]) minIdx = rc;
    if(idx != minIdx){
        swap(v[idx], v[minIdx]);
        heapify(v, minIdx);
    }
}

void buildMinHeap(vector<int>& v) { // O(n)
    for (int i=(v.size()-1)/2; i >= 1; --i)
        heapify(v, i);
}

void print(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) cout << v[i] << ' ';
    cout<<endl;
}
// --------------------------------------------------------------


// Heap Sort - O(n log n)// -------------------------------------
void heapifyHeapSort(vector<int> &v, int idx, int n){
    int lc = 2*idx, rc = 2*idx+1, newIdx = idx;
    if(lc <= n && v[lc] > v[newIdx]) newIdx = lc;
    if(rc <= n && v[rc] > v[newIdx]) newIdx = rc;
    if(newIdx != idx){
        swap(v[newIdx], v[idx]);
        heapifyHeapSort(v, newIdx, n);
    }
}

void buildMaxHeapSort(vector<int> &v, int n){
    for(int i=n/2; i>=1; --i)
        heapifyHeapSort(v, i, n);
}

void heapSort(vector<int> &v){
    int n = v.size()-1;
    buildMaxHeapSort(v, n);
    while(n>1){
        swap(v[1], v[n]);
        heapifyHeapSort(v, 1, --n);
    }
}
// --------------------------------------------------------------


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //  // Min-heap
    // Heap minh(true);
    // for (int x : {5, 3, 8, 1, 7, 2}) minh.push(x);
    // cout << "Min-heap after pushes: "; minh.print();     // expect root = 1
    // cout << "Peek min: " << minh.get() << "\n";          // 1
    // while (!minh.isEmpty()) {
    //     cout << "Pop " << minh.get() << " -> ";
    //     minh.pop();
    //     minh.print();
    // }

    // // Build Heap from an array - Floyd's Algo - O(n)
    // cout<<endl<<"Build Heap"<<endl;
    // vector<int> v, arr{4, 3, 5, 6, 1, 7, 8, 2, 9};
    // v.reserve(arr.size() + 1);
    // v.push_back(-1);
    // v.insert(v.end(), arr.begin(), arr.end());
    // buildMinHeap(v);
    // print(v);

    // // Heap Sort
    // cout<<endl<<"Heap Sort"<<endl;
    // vector<int> v, arr{4, 3, 5, 6, 1, 7, 8, 2, 9};
    // v.reserve(arr.size() + 1);
    // v.push_back(-1);
    // v.insert(v.end(), arr.begin(), arr.end());
    // heapSort(v);
    // print(v);

    // PQ STL
    priority_queue<int> pq; // max heap
    priority_queue<int, vector<int>, greater<int>> pq1; // min heap

    return 0;
}


// PQ STL - custom class
// class minHeap(){
// public:
//     void operator()(int a, int b){
//         return a>b;
//     }
// };

// int main(){
//     priority_queue<int, vector<int>, minHeap> pq;
//     return 0;
// }