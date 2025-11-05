// O(n^2) soln - DFS from each node!
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    set<vector<int>> extraEdge;

    void dfs(int u, int parent){
        visited[u] = true;
        for(auto &v: graph[u]){
            if(v==parent) continue;
            if(visited[v]) extraEdge.insert({u, v});
            else dfs(v, u);
        }
        visited[u]=false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph.assign(n+1, {});
        vector<int> ans;
        visited.assign(n+1, false);
        for(auto &x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=1; i<=n; ++i) if(!visited[i]) dfs(i, -1);
        for(auto &x: edges){
            if(extraEdge.count(x)){
                cout<<x[0]<<","<<x[1]<<endl;
                ans = x;
            }
        }
        return ans;
    }
};

// Path compression (your parent[x] = find(parent[x])): flattens paths when you call find, making future finds near O(1).
// Rank/size (keep sz or rank and attach smaller under larger): prevents tall trees from forming, 
// so initial finds are also cheap and worst-case performance is stable
// Best practice: use both (rank/size + path compression).




// O(n * aplha(n)) - solution using Union Find!
class Solution {
public:
    /*
    vector<vector<int>> graph;
    vector<bool> visited;
    set<vector<int>> extraEdge;

    void dfs(int u, int parent){
        visited[u] = true;
        for(auto &v: graph[u]){
            if(v==parent) continue;
            if(visited[v]) extraEdge.insert({u, v});
            else dfs(v, u);
        }
        visited[u]=false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph.assign(n+1, {});
        vector<int> ans;
        visited.assign(n+1, false);
        for(auto &x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=1; i<=n; ++i) if(!visited[i]) dfs(i, -1);
        for(auto &x: edges){
            if(extraEdge.count(x)){
                cout<<x[0]<<","<<x[1]<<endl;
                ans = x;
            }
        }
        return ans;
    }
    */

    vector<int> parent, rank;
    int findFunc(int v){
        if(parent[v] != v) parent[v] = findFunc(parent[v]); 
        return parent[v];
    }

    bool unionFunc(int i1, int i2){
        int p1=findFunc(i1), p2=findFunc(i2);
        if(p1 == p2) return false;
        // this problem can be done without using rank but a first find on a long chain can be O(n).
        if(rank[p1] >= rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.assign(n+1, 0);
        for(int i=0; i<=n; ++i) parent[i] = i;
        rank.assign(n+1, 1);
        for(auto &x: edges)
            if(!unionFunc(x[0], x[1])) return x;
        return {};
    }
};