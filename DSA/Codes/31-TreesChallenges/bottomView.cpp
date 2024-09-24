void bottomViewHelper(Node* root, int level, int dist, map<int, pair<int, int>> &p){
        if(root == NULL)
            return;
        if(p.find(dist) == p.end())
            p.insert({dist, {root->data, level}});
        else{
            pair<int, int> px = p[dist];
            if(level >= px.second)
                p[dist] = {root->data, level};
        }
        bottomViewHelper(root->left, level+1, dist-1, p);
        bottomViewHelper(root->right, level+1, dist+1, p);
    }
    
    vector <int> bottomView(Node *root) {
        vector<int> v;
        v.clear();
        map<int, pair<int, int>> p;
        bottomViewHelper(root, 0, 0, p);
        for(auto x:p)
            v.push_back(x.second.first);
        return v;
    }