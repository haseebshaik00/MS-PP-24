class Solution {
public:
    void vTravel(TreeNode* root, map<int, vector<pair<int, int>>> &m, int r, int c){
        if(root == NULL) return;
        vTravel(root->left, m, r+1, c-1);
        m[c].push_back({r, root->val});
        vTravel(root->right, m, r+1, c+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        map<int, vector<pair<int, int>>> m;
        vTravel(root, m, 0, 0);
        for(auto x:m){
            sort(x.second.begin(), x.second.end(), [](pair<int, int> a, pair<int, int> b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            vector<int> v1;
            for (auto p : x.second)
                v1.push_back(p.second);
            v.push_back(v1);
        }
        return v;
    }
};