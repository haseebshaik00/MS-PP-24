class Solution {
public:
    // Prim's Algo - Min Spanning Tree
    int minCostConnectPoints(vector<vector<int>>& points) {
        using P = pair<vector<int>, int>;
        int n = points.size(), sum=0;
        set<vector<int>> visited;
        auto cmp = [](const P&a, const P&b) {return a.second > b.second;};
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        pq.push({points[0], 0});
        while(!pq.empty() && visited.size()!=n){
            auto [node, dist] = pq.top(); pq.pop();
            if(visited.count(node)) continue;
            sum += dist;
            visited.insert(node);
            for(auto &y: points)
                if(y!=node && !visited.count(y))
                    pq.push({y, abs(node[0]-y[0]) + abs(node[1]-y[1])});
        }
        return sum;
    }
};