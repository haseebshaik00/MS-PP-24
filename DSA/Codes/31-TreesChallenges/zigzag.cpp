vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            vector<int> v;
            TreeNode* temp = q.front();
            q.push(NULL);
            while(temp != NULL){
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
                temp = q.front();
            }
            q.pop();
            if(c%2 != 0){
                for(int i=0; i<v.size()/2; i++)
                    swap(v[i], v[v.size()-1-i]);
            }
            ans.push_back(v);
            c++;
        }
        return ans;
    }