int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size(), ans = 0;
        priority_queue<node, vector<node>, greater<node>> pq;
        for(int i=0; i<n; i++)
            pq.push({matrix[0][i], {0, i}});
        while(k--){
            node curr = pq.top();
            pq.pop();
            ans = curr.first;
            int i = curr.second.first, j=curr.second.second;
            if(i+1 < n) pq.push({matrix[i+1][j], {(i+1), j}});
        }
        return ans;
    }