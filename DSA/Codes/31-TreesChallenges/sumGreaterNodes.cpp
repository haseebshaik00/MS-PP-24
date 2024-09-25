void addSum(Node* root, int &sum){
    if(root == NULL)
        return;
    addSum(root->right, sum);
    sum += root->data;
    root->data = sum;
    addSum(root->left, sum);
}

Node* modify(Node *root)
{
    int sum = 0;
    addSum(root, sum);
    return root;
}