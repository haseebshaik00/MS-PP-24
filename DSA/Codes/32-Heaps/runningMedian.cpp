class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}
    
    void addNum(int num) {
        // push in maxH to get the max of the lower half, now send it to minH 
        // to sort itself in order and get the min in higher half
        // now the heaps are sorted and median lies at the top of each heap
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); maxHeap.pop();
        // now to maintain the ordering we always keep maxH size+1 of minH or
        // equal which will help to cal the median easily
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return ((maxHeap.top() + minHeap.top()) * 1.0)/2;
    }
};
