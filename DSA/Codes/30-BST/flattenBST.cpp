class Solution {
  Node* prev = NULL;
  public:
    void flatten(Node *root){
        if(!root) return;
        flatten(root->right);
        Node* L = root->left;
        root->right = prev;
        root->left = NULL;
        prev = root;
        flatten(L);
    }
  
    Node *flattenBST(Node *root) {
        if(!root) return root;
        prev = NULL;
        flatten(root);
        return prev;
    }
};