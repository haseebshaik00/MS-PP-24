class Solution {
public:
    // Can also be done using djikstra's logic!
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), t = -1;
        using P = pair<int, vector<int>>;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        auto cmp = [](const P& a, const P& b) { return a.first > b.first; };
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int dirs[5] = {1, 0, -1, 0, 1};
        while(!pq.empty()){
            if(pq.top().first > t) t = pq.top().first;
            auto [water, currV] = pq.top(); pq.pop();
            if(currV[0]==n-1 && currV[1]==n-1) break;
            for(int i=0; i<4; ++i){
                int x = currV[0]+dirs[i], y=currV[1]+dirs[i+1];
                if(x<0 || y<0 || x>=n || y>=n || visited[x][y]) continue;
                pq.push({grid[x][y], {x, y}});
                visited[x][y]=true;
            }
        }
        return t;
    }
};