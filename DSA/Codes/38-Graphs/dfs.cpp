#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, list<int>> l;

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(int x, map<int, bool> &visited){
        cout<<x<<" ";
        visited[x] = true;
        for(auto y:l[x])
            if(!visited[y])
                dfs_helper(y, visited);
    }

    void dfs(int x){
        map<int, bool> visited;
        dfs_helper(x, visited);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);

    return 0;
}

// gfg
vector<int> v;
    
    void dfs(const int x, map<int, bool> &visited, const vector<vector<int>>& adj){
        v.push_back(x);
        visited[x] = true;
        for(auto y:adj[x])
            if(!visited[y])
                dfs(y, visited, adj);
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        map<int, bool> m;
        dfs(0, m, adj);
        return v;
    }