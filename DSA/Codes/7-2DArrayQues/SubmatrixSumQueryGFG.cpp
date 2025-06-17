class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        for(auto &x: Queries){
            int a=x[0], b=x[1], c=x[2], d=x[3];
            m[a][b] += 1;
            if(d+1<n) m[a][d+1] -= 1;
            if(c+1<n) m[c+1][b] -= 1;
            if(d+1<n && c+1<n) m[c+1][d+1] += 1;
        }
        for(int i=0; i<n; i++)
            for(int j=1; j<n; j++)
                m[i][j] += m[i][j-1];
        for(int j=0; j<n; j++)
            for(int i=1; i<n; i++)
                m[i][j] += m[i-1][j];
        return m;
    }
};