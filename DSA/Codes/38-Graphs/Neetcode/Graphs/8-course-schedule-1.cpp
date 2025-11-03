// A topological sorting of nodes in a graph is an ordering of the nodes in the graph where every 
// node appears only after all the nodes pointing to it have appeared. For example, for a graph with 
// 4 nodes and these relations: a→b , a→c , b→d , c→d , there are two acceptable topological 
// sorts: a, b, c, d and a, c, b, d .
// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for 
// every directed edge u→v, vertex u comes before v in the ordering. There may be several topological orderings for a graph.
// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.


// https://chatgpt.com/share/6907e9fc-3bbc-800d-89e2-017bce42a32c = check the last prompt

// DFS
class Solution {
public:
    vector<int> colors;
    vector<vector<int>> graph;

    bool dfs(int u){
        colors[u] = 1;
        for(auto &v: graph[u]){
            if(colors[v] == 1) return false;
            if(!colors[v] && !dfs(v)) return false;
        }
        colors[u] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, {});
        colors.assign(numCourses, 0);
        for(auto &x: prerequisites) graph[x[1]].push_back(x[0]);
        for(int vertex=0; vertex<numCourses; ++vertex)
            if(!colors[vertex] && !dfs(vertex)) return false;
        return true;
    }
};

// BFS - Kahn's algo
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        for(auto &x: prerequisites){
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
        for(int i=0; i<numCourses; ++i) 
            if(!inDegree[i]) q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto &v: graph[u]){
                --inDegree[v];
                if(!inDegree[v]) q.push(v);
            }
        }
        for(auto &x: inDegree) if(x) return false;
        return true;
    }