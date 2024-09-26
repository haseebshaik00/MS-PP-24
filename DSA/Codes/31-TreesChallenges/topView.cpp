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