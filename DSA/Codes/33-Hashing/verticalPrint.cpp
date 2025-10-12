class Solution {
public:
    //O(n log n)
    map<int, map<int, vector<int>>> nodes;
    void dfs(TreeNode* root, int level, int dist){
        if(!root) return;
        dfs(root->left, level+1, dist-1);
        nodes[dist][level].push_back(root->val);
        dfs(root->right, level+1, dist+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for(auto &x: nodes){
            vector<int> v;
            for(auto &y: x.second){
                sort(y.second.begin(), y.second.end());
                for(auto &z: y.second) v.push_back(z);
            }
            ans.push_back(v);
        }
        return ans;
    }
};