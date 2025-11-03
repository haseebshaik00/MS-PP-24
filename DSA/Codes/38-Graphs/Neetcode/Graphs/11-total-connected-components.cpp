class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    void dfs(int u){
        visited[u] = true;
        for(auto &v: graph[u])
            if(!visited[v]) dfs(v);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        graph.assign(n, {}); 
        visited.assign(n, false);
        int ans = 0;
        for(auto &x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0; i<n; ++i){
            if(visited[i]) continue;
            ++ans; dfs(i);
        }
        return ans;
    }
};
