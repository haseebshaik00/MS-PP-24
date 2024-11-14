void topSortHelper(const int i, map<int, bool> &visited, const vector<vector<int>>& adj){
        visited[i] = true;
        for(int x: adj[i]){
            if(!visited[x])
                topSortHelper(x, visited, adj);
        }
        s.push(i);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        map<int, bool> visited;
        int n = adj.size();
        for(int i=0; i<n; i++){
            if(!visited[i])
                topSortHelper(i, visited, adj);
        }
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }