bool checkSymmetry(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
            return false;
        if(checkSymmetry(root1->left, root2->right) && 
            checkSymmetry(root1->right, root2->left) && (root1->val == root2->val))
            return true;
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);
    }