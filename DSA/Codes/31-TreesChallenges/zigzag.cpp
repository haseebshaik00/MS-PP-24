vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> curr;
        bool reverseFlag = false;
        q.push(root); q.push(nullptr);
        while(!q.empty()){
            if(!q.front()){
                q.pop();
                if(reverseFlag) reverse(curr.begin(), curr.end());
                reverseFlag = !reverseFlag;
                ans.push_back(curr);
                curr.clear();
                if(!q.empty()) q.push(nullptr);
                continue;
            }
            TreeNode* node = q.front(); q.pop();
            curr.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }