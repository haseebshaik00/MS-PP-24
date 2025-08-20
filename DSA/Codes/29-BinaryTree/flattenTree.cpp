// O(n) solution - use reverse preorder approach! = right-left-root!
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }