class Solution {
public:
    // Dijkstra-with-stops solution - O((K+1) * E * log(n*(K+1)))
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     using P = pair<int, int>;
    //     using P1 = pair<int, vector<int>>;
    //     const int INF=1e9;
    //     vector<vector<P>> graph(n);
    //     for(auto &x: flights) graph[x[0]].push_back({x[1], x[2]});
    //     auto cmp = [](auto &a, auto &b) {return a.first > b.first;};
    //     priority_queue<P1, vector<P1>, decltype(cmp)> pq(cmp);
    //     pq.push({0, {src, 0}}); // dist, node, edges
    //     vector<vector<int>> dist(n, vector<int>(k + 2, INF));
    //     dist[src][0] = 0; 
    //     int ans = INF, maxE = k+1;
    //     while(!pq.empty()){
    //         int path=pq.top().first, city=pq.top().second[0],
    //             edges=pq.top().second[1]; pq.pop();
    //         if(city == dst) return path;
    //         if(edges == maxE) continue;
    //         for(auto &neig: graph[city]){
    //             auto [v, w] = neig;
    //             if(path+w < dist[v][edges+1]){
    //                 dist[v][edges+1] = path+w;
    //                 pq.push({path+w, {v, edges+1}});
    //             }
    //         }
    //     }
    //     for(int i=0; i<=maxE; ++i) ans = min(ans, dist[dst][i]);
    //     return (ans == INF) ? -1 : ans;
    // }

    // Bellman Ford's(k+1 edges) - O((K+1)·E)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src]=0;
        for(int i=0; i<=k; ++i){
            vector<int> next = dist;
            for(auto &x: flights){
                auto u=x[0], v=x[1], w=x[2];
                if(dist[u] == INF) continue;
                if(next[v] > dist[u]+w) next[v] = dist[u]+w;
            }
            dist.swap(next);
        }
        return (dist[dst] == INF) ? -1 : dist[dst];
    }
};