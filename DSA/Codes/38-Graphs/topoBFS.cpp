vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<int> incomingEdge(n, 0);
        vector<int> v;
        queue<int> q;
        for(int i=0; i<n; i++)
            for(auto x:adj[i])
                incomingEdge[x]++;
        for(int i=0; i<n; i++)
            if(!incomingEdge[i]) q.push(i);
        while(!q.empty()){
            int node = q.front();
            v.push_back(node);
            q.pop();
            for(auto x: adj[node]){
                incomingEdge[x]--;
                if(!incomingEdge[x])
                    q.push(x);
            }
        }
        return v;
    }