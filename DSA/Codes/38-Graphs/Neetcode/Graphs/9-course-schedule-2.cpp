// DFS

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> colors, ans;

    bool dfs(int u){
        colors[u] = 1;
        for(auto &v: graph[u]){
            if(colors[v] == 1) return false;
            if(!colors[v] && !dfs(v)) return false;
        }
        colors[u] = 2;
        ans.push_back(u);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, {});
        colors.assign(numCourses, 0);
        for(auto &x: prerequisites) graph[x[1]].push_back(x[0]);
        for(int i=0; i<numCourses; ++i)
            if(!colors[i] && !dfs(i)) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// BFS
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0), ans;
        queue<int> q;
        for(auto &x: prerequisites){
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
        for(int i=0; i<numCourses; ++i) 
            if(!inDegree[i]) q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(auto &v: graph[u]){
                --inDegree[v];
                if(!inDegree[v]) q.push(v);
            }
        }
        for(auto &x: inDegree) if(x) return {};
        return ans;
    }