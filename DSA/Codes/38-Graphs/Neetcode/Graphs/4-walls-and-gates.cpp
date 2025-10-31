void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> q;
        int dirs[5] = {1,0,-1,0,1};
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(!grid[i][j]) q.push({i, j});
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            for(int k=0; k<4; ++k){
                int x = i+dirs[k], y=j+dirs[k+1];
                if(x<0 || y<0 || x>=m || y>=n || 
                    grid[x][y]==-1 || (grid[x][y] <= grid[i][j] + 1)) continue;
                grid[x][y] = grid[i][j] + 1;
                q.push({x, y});
            }
        }
    }