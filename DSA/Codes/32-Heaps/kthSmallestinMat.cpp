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

// leetcode
int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        struct Node {int val, i, j;};
        auto cmp = [](const Node &a, const Node &b){ return a.val > b.val;};
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        for(int i=0; i<n; i++) pq.push({matrix[i][0], i, 0});
        while(--k){
            Node top = pq.top(); pq.pop();
            if(top.j + 1 < n) pq.push({matrix[top.i][top.j+1], top.i, top.j+1});
        }
        return pq.top().val;
    }