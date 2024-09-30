vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> v;
        priority_queue<pair<int ,pair<int, int>>> p;
        set<pair<int, int>> s;
        p.push({(B[n-1] + A[n-1]), {(n-1), (n-1)}});
        s.insert({(n-1), (n-1)});
        while(k--){
            pair<int ,pair<int, int>> curr = p.top();
            p.pop();
            v.push_back(curr.first);
            int i = curr.second.first, j=curr.second.second;
            if((i-1) >= 0){
                if(s.find({i-1, j}) == s.end()){
                    s.insert({i-1, j});
                    p.push({A[i-1]+B[j], {i-1, j}});
                }
            }
            if((j-1) >= 0){
                if(s.find({i, j-1}) == s.end()){
                    s.insert({i, j-1});
                    p.push({A[i]+B[j-1], {i, j-1}});
                }
            }
        }
        return v;
    }