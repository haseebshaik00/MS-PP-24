class Solution {
public:
    bool checkBp(int i, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        color[i] = 0;
        q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto y: graph[x]){
                if(color[y] == -1){
                    color[y] = !color[x];
                    q.push(y);
                }
                else{
                    if(color[y] == color[x])
                        return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(!checkBp(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};