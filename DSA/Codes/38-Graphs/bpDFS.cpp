class Solution {
public:
    bool bpHeper(int i, vector<vector<int>>& graph, vector<int> &color, int colorNode){
        color[i] = colorNode;
        for(auto x: graph[i]){
            if(color[x]==-1){
                if(!bpHeper(x, graph, color, !colorNode))
                    return false;
            }
            else if(color[x] == colorNode)
                    return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(!bpHeper(i, graph, color, 0))
                    return false;
            }
        }
        return true;
    }
};