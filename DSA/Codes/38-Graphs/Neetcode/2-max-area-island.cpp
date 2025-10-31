
.cclass Solution {
public:
    int m=0, n=0, ans=0;
    
    void bfs(vector<vector<int>>& grid, int i, int j){
        int dist[5] = {1, 0, -1, 0, 1}, cnt=0;
        queue<pair<int, int>> q;
        grid[i][j]=0;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop(); ++cnt;
            for(int k=0; k<4; ++k){
                int x = p.first+dist[k], y=p.second+dist[k+1];
                if(x<0 || x>=m || y<0 || y>=n || !grid[x][y]) continue;
                grid[x][y] = 0;
                q.push({x, y});
            }
        }
        ans = max(ans, cnt);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(grid[i][j]) bfs(grid, i, j);
        return ans;
    }
};