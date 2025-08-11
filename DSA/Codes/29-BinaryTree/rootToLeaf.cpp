class Solution {
  public:
    vector<vector<int>> ans;
    void trackLeaves(Node* root, vector<int> &curr){
        if (!root) return;
        curr.push_back(root->data);
        if(!root->left && !root->right) ans.push_back(curr);
        else{
            trackLeaves(root->left, curr);
            trackLeaves(root->right, curr);
        }
        curr.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<int> curr;
        trackLeaves(root, curr);
        return ans;
    }
};