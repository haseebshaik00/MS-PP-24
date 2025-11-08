class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using P = pair<int, int>;
        const int mx = 1e9;
        vector<vector<P>> graph(n+1);
        for(auto &x: times) graph[x[0]].push_back({x[1], x[2]});
        vector<int> dist(n+1, mx); dist[k] = 0;
        auto cmp = [](const P&a, const P&b) {return a.first > b.first;};
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        pq.push({0, k});
        while(!pq.empty()){
            auto [path, node] = pq.top(); pq.pop();
            if(path > dist[node]) continue;
            for(auto &[v, w]: graph[node]){
                if(path + w < dist[v]){
                    dist[v] = path+w;
                    pq.push({path+w, v});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == mx ? -1 : ans;
    }
};