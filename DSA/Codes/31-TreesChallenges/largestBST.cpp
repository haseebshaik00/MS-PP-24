class Solution {
  public:
    
    struct Info{
        bool bst;
        int size, mn, mx;
    };
    
    Info largestFind(Node *root) {
        if(!root) return { true, 0, INT_MAX, INT_MIN };
        Info l = largestFind(root->left), r = largestFind(root->right);
        if(l.bst && r.bst && l.mx < root->data && root->data < r.mn)
            return {true, 1+l.size+r.size, min(l.mn, root->data), max(r.mx, root->data)};
        else return {false, max(l.size, r.size), INT_MIN, INT_MAX};
    }
    
    int largestBst(Node *root) {
        return largestFind(root).size;
    }
};

///////////////////

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