map<int, pair<int, int>> m;
    void topCal(Node* root, int distH, int height){
        if(!root) return;
        if(!m.count(distH) || (m.count(distH) && m[distH].first > height)) 
            m[distH] = make_pair(height, root->data);
        topCal(root->left, distH-1, height+1);
        topCal(root->right, distH+1, height+1);
    }
    
    vector<int> topView(Node *root) {
        if(!root) return {};
        topCal(root, 0, 0);
        vector<int> ans;
        for(auto &x: m) ans.push_back(x.second.second);
        return ans;
    }

void topNodes(Node* root, map<int, pair<int, int>> &hashMap, int level, int dist){
        if(root == NULL)
            return;
        topNodes(root->left, hashMap, level+1, dist-1);
        if(hashMap.find(dist) == hashMap.end()){
            hashMap.insert({dist, {root->data, level}});
        }
        else{
            pair<int, int> p = hashMap[dist];
            if(level < p.second)
                hashMap[dist] = {root->data, level};
        }
        topNodes(root->right, hashMap, level+1, dist+1);
    }
    
    vector<int> topView(Node *root)
    {
        map<int, pair<int, int>> hashMap;
        vector<int> v;
        topNodes(root, hashMap, 0, 0);
        for(auto x : hashMap){
            v.push_back(x.second.first);
        }
        return v;
    }