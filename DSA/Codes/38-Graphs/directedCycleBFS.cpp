
vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n= adj.size(), cnt==0;
        vector<int> incomingEdge(n, 0);
        queue<int> q;
        for(int i=0; i<n; i++)
            for(auto x:adj[i])
                incomingEdge[x]++;
        for(int i=0; i<n; i++)
            if(!incomingEdge[i]) q.push(i);
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(auto x: adj[node]){
                incomingEdge[x]--;
                if(!incomingEdge[x])
                    q.push(x);
            }
        }
        return cnt!=n;
    }

// 

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> v(n, 0);
        map<int, list<int>> m;
        queue<int> q;
        int cnt=0;
        for(auto x: p)
            m[x[1]].push_back(x[0]);
        for(int i=0; i<n; i++)
            for(int x: m[i])
                v[x]++;
        for(int i=0; i<n; i++)
            if(v[i] == 0)
                q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            cnt++;
            for(auto y: m[x]){
                v[y]--;
                if(v[y]==0)
                    q.push(y);
            }
        }
        return cnt == n;
    }
};