class Solution {
public:
    int m, n;
    void bfs(queue<pair<int, int>> &q, vector<vector<int>>& heights, 
                vector<vector<bool>> &wc){
        int dirs[5] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            for(int k=0; k<4; ++k){
                int x = i+dirs[k], y=j+dirs[k+1];
                if(x<0 || y<0 || x>=m || y>=n || wc[x][y]
                    || heights[x][y] < heights[i][j]) continue;
                wc[x][y]=true;
                q.push({x, y});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        vector<vector<bool>> waterContPQ(m, vector<bool>(n, false)), 
                            waterContAQ(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        queue<pair<int, int>> pq, aq;
        for(int i=0; i<m; ++i) {pq.push({i, 0}); waterContPQ[i][0]=1;}
        for(int j=0; j<n; ++j) {pq.push({0, j}); waterContPQ[0][j]=1;}
        for(int i=0; i<m; ++i) {aq.push({i, n-1}); waterContAQ[i][n-1]=1;}
        for(int j=0; j<n; ++j) {aq.push({m-1, j}); waterContAQ[m-1][j]=1;}
        bfs(pq, heights, waterContPQ);
        bfs(aq, heights, waterContAQ);
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(waterContPQ[i][j] && waterContAQ[i][j]) 
                    ans.push_back({i, j});
        return ans;
    }
};