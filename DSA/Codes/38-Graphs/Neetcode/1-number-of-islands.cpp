class Solution {
public:
    int m=0, n=0, cnt=0;
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j); dfs(grid, i-1, j);
        dfs(grid, i, j+1); dfs(grid, i, j-1);
    }

    void bfs(vector<vector<char>>& grid, int i, int j){
        int dist[5] = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int x = p.first + dist[i], y=p.second + dist[i+1];
                if(x<0 || y<0 || x>=m || y>=n) continue;
                if(grid[x][y] == '1'){
                    q.push({x, y});
                    grid[x][y] = '0';
                }
            }
        }
    } 

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                // if(grid[i][j]=='1') {++cnt; dfs(grid, i, j);} - DFS Soln
                if(grid[i][j]=='1') {++cnt; bfs(grid, i, j);} // - BFS Soln
        return cnt;
    }
};