class Solution {
public:
    int n, m, c=0;
    void bfs(vector<vector<bool>> &visited, vector<vector<char>> &grid, int i, int j){
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // Cardinal directions
            // {-1, -1}, {-1, 1}, {1, -1}, {1, 1} Diagonal directions
        };
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cout<<i<<" "<<j<<endl;
                    bfs(visited, grid, i, j);
                    c++;
                }
            }
        }
        return c;
    }
};