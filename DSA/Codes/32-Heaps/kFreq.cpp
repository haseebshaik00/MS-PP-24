vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(auto &x: nums) freq[x]++;
        struct Node {int val, count;};
        auto comp = [](const Node &a, const Node &b) {return a.count>b.count;};
        priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);
        for(auto &x: freq){
            int val=x.first, count=x.second;
            if(pq.size() < k) pq.push({val, count});
            else if (pq.top().count < count){
                pq.pop(); pq.push({val, count});
            }
        }
        while(!pq.empty()) {ans.push_back(pq.top().val); pq.pop();}
        return ans;
    }