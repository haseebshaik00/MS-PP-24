class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size(), freshOrg=0, time=-1;
        queue<pair<int, int>> q;
        int dirs[5] = {1, 0, -1, 0, 1};
        for(int i=0; i<m; ++i) 
            for(int j=0; j<n; ++j)
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) freshOrg++;

        // No need - while loops handles everything!
        // if (fresh == 0) return 0;     // nothing to rot
        // if (q.empty()) return -1;     // no source to start rotting

        q.push({-1, -1});
        while(!q.empty() && fresh){
            auto [i, j] = q.front(); q.pop();
            if(i==-1){
                ++time;
                if(!q.empty()) q.push({-1, -1});
            }
            for(int k=0; k<4; ++k){
                int x=i+dirs[k], y=j+dirs[k+1];
                if(x<0 || y<0 || x>=m || y>=n || grid[x][y]!=1) continue;
                grid[x][y] = 2; q.push({x, y});
                --freshOrg;
            }
        }
        return freshOrg ? -1 : time;
    }
};