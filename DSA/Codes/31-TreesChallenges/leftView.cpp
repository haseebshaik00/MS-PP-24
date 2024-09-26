void leftNodes(Node *root, vector<int> &v, int level, int &maxLevel){
    if(root == NULL)
        return;
    if(level > maxLevel){
        maxLevel = level;
        v.push_back(root->data);
    }
    leftNodes(root->left, v, level+1, maxLevel);
    leftNodes(root->right, v, level+1, maxLevel);
}

vector<int> leftView(Node *root)
{
   vector<int> v;
   int maxLevel = -1;
   leftNodes(root, v, 0, maxLevel);
   return v;
}