typedef pair<int, int> pp;

class Functors{
public:
    bool operator()(pp p1, pp p2){
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int n=nums.size();
        vector<int> v;
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        priority_queue<pp, vector<pp>, Functors> pq(m.begin(), m.end());
        while(k--){
            v.push_back(pq.top().first);
            pq.pop();
        }
        return v;
    }
};