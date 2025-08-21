//// Floor

int ans = -1;
void findFloor(TreeNode<int> * root, int X){
    if(!root) return;
    if(root->val > X) return findFloor(root->left, X);
    ans = root->val;
    if(root->val == X) return;
    findFloor(root->right, X);
}

int floorInBST(TreeNode<int> * root, int X)
{
    ans = -1;
    findFloor(root, X);
    return ans;
}


//// Ceil

int ans = -1;
void findBSTCeil(BinaryTreeNode<int> *root, int X){
    if(!root) return;
    if(root->data < X) return findBSTCeil(root->right, X);
    ans = root->data;
    if(root->data == X) return;
    findBSTCeil(root->left, X);
}

int findCeil(BinaryTreeNode<int> *node, int x){
    ans = -1;
    findBSTCeil(node, x);
    return ans;
}