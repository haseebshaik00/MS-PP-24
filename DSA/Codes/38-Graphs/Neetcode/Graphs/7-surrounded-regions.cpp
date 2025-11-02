class Solution {
public:
    int m=0, n=0;
    void bfs(vector<vector<char>>& board, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j}); board[i][j] = '#';
        int dirs[5] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            for(int k=0; k<4; ++k){
                int x=i+dirs[k], y=j+dirs[k+1];
                if(x<0 || y<0 || x>=m || y>=n || board[x][y]!='O') continue;
                board[x][y] = '#'; q.push({x, y});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m=board.size(), n=board[0].size();
        for(int i=0; i<m; ++i){
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        for(int j=1; j<n-1; ++j){
            if(board[0][j] == 'O') bfs(board, 0, j);
            if(board[m-1][j] == 'O') bfs(board, m-1, j);
        }
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                board[i][j] = ((board[i][j] == '#') ? 'O' : 
                                (board[i][j] == 'O') ? 'X' : board[i][j]);
    }
};