class BSTNode{
public:
    int mini;
    int maxi;
    int size;
    
    BSTNode(int miniV, int maxiV, int sizeV){
        mini = miniV;
        maxi = maxiV;
        size = sizeV;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    BSTNode largestBSTree(Node* root){
        if(!root)
            return BSTNode(INT_MAX, INT_MIN, 0);
        BSTNode left = largestBSTree(root->left);
        BSTNode right = largestBSTree(root->right);
        if(root->data > left.maxi && root->data < right.mini)
            return BSTNode(min(left.mini, root->data), max(right.maxi, root->data), 
            left.size+right.size+1);
        return BSTNode(INT_MIN, INT_MAX, max(left.size, right.size));
    }
    
    int largestBst(Node *root)
    {
    	return largestBSTree(root).size;
    }
};