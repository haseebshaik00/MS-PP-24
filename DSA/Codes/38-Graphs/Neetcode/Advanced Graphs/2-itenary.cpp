class Solution {
public:
    // Hierholzer’s algorithm (Eulerian path) It’s a classic algorithm to construct a path 
    // that uses every edge exactly once in a graph (an Eulerian path/trail).
    unordered_map<string, vector<string>> graph;
    vector<string> ans;

    void dfs(string u){
        auto &v = graph[u];
        while(!v.empty()){
            string x = v.back();
            v.pop_back();
            dfs(x);
        }
        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x: tickets) graph[x[0]].push_back(x[1]);
        for(auto &x: graph) sort(x.second.rbegin(), x.second.rend());
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};