// preorder vector: [root, left-subtree..., right-subtree...], with nullopt for nulls
TreeNode* buildPre(const vector<optional<int>>& a, size_t& i) {
    if (i >= a.size() || !a[i]) { ++i; return nullptr; }   // consume null
    TreeNode* node = new TreeNode(*a[i]++);
    node->left  = buildPre(a, i);
    node->right = buildPre(a, i);
    return node;
}
TreeNode* buildTreePre(const vector<optional<int>>& a) {
    size_t i = 0; 
    return buildPre(a, i);
}