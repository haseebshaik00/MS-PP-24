TreeNode* buildTree(const vector<optional<int>>& a, size_t i = 0) {
    if (i >= a.size() || !a[i]) return nullptr;
    TreeNode* node = new TreeNode(*a[i]);
    node->left  = buildTree(a, 2*i + 1);
    node->right = buildTree(a, 2*i + 2);
    return node;
}