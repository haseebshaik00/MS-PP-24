class Solution {
public:
    void dfs(TreeNode* root, vector<long long int> &v, int level){
        if(!root) return;
        if(level == (int)v.size()) v.push_back(0);
        v[level] += root->val;
        dfs(root->left, v, level+1);
        dfs(root->right, v, level+1);
    }

    int maxLevelSum(TreeNode* root) {
        long long int ans = LLONG_MIN;
        vector<long long int> v;
        int idx = -1;
        dfs(root, v, 0);
        for(int i=0; i<v.size(); i++){
            if(v[i] > ans){
                idx = i;
                ans = v[i];
            }
        }
        return idx+1;
    }
};