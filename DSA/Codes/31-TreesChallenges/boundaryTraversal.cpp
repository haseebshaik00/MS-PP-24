class Solution {
  public:
    vector<int> ans, ansR;
    
    void leftBoundary(Node *root){
        if(!root) return;
        if(!root->left && !root->right) return;
        ans.push_back(root->data);
        if(root->left) leftBoundary(root->left);
        else leftBoundary(root->right);
    }
    
    void leafTraversal(Node* root){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left);
        leafTraversal(root->right);
    }
    
    void rightBoundary(Node *root){
        if(!root) return;
        if(!root->left && !root->right) return;
        ansR.push_back(root->data);
        if(root->right) rightBoundary(root->right);
        else rightBoundary(root->left);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        ans.clear(); ansR.clear();
        if(!root) return {};
        if(root->left || root->right) ans.push_back(root->data);
        leftBoundary(root->left);     // not root
        leafTraversal(root);          // all leaves L->R
        rightBoundary(root->right);   // collect, then reverse
        reverse(ansR.begin(), ansR.end());
        ans.insert(ans.end(), ansR.begin(), ansR.end());
        return ans;
    }
};
