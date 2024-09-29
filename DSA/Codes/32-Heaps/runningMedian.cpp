class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    double ans;
    
    MedianFinder() {
        ans = 0.0;
    }
    
    void addNum(int num) {
        if(pq1.size() < pq2.size()){
            if(num > ans){
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
            else{
                pq1.push(num);
            }
            ans = (pq1.top()+pq2.top())/2.0;
        }
        else if(pq1.size() == pq2.size()){
            if(num <= ans){
                pq1.push(num);
                ans = pq1.top();
            }
            else{
                pq2.push(num);
                ans = pq2.top();
            }
        }
        else{
            if(num <= ans){
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
            else{
                pq2.push(num);
            }
            ans = (pq1.top()+pq2.top())/2.0;
        }
        cout<<ans<<endl;
    }
    
    double findMedian() {
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */