vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
       struct Node {int val, i, j;};
       auto cmp = [](const Node &a, const Node &b){ return a.val > b.val; };
       priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
       vector<int> ans;
       for(int i=0; i<K; ++i) pq.push({arr[i][0], i, 0});
       while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int val = top.val, i=top.i, j=top.j;
            ans.push_back(val);
            if(j+1<K) pq.push({arr[i][j+1],i,j+1});
       }
       return ans;
    }