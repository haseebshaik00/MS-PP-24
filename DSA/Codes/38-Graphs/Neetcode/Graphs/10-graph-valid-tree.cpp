class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;

    bool dfs(int u, int parent){
        visited[u] = 1;
        for(auto &v: graph[u]){
            if(visited[v]==1 && v==parent) continue;
            if(visited[v]==1) return false;
            if(!visited[v] && !dfs(v, u)) return false;
        }
        visited[u] = 2;
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        graph.assign(n, {});
        visited.assign(n, 0);
        for(auto &x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        if(!dfs(0, -1)) return false;
        for(auto &x: visited) if(!x) return false;
        return true;
    }
};
