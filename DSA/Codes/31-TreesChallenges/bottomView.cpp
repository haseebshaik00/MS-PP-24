map<int, pair<int, int>> m;
    void bottomCal(Node* root, int distH, int height){
        if(!root) return;
        if(!m.count(distH) || m[distH].first <= height)
            m[distH] = make_pair(height, root->data);
        bottomCal(root->left, distH-1, height+1);
        bottomCal(root->right, distH+1, height+1);
    }
    
    vector<int> bottomView(Node *root) {
        if(!root) return {};
        vector<int> ans;
        bottomCal(root, 0, 0);
        for(auto &x: m) ans.push_back(x.second.second);
        return ans;
    }

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