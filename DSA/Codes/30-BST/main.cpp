#include<bits/stdc++.h>
using namespace std;

class BST{
public:
    int data;
    BST* left;
    BST* right;

    BST(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

BST* insertNode(BST *root, int d){
    if(root == NULL)
        return new BST(d);
    if(d <= root->data)
        root->left = insertNode(root->left, d);
    else
        root->right = insertNode(root->right, d);
    return root;
}

BST* build(){
    int d;
    cin>>d;
    BST* root = NULL;
    while(d!=-1){
        root = insertNode(root, d);
        cin>>d;
    }
    return root;
}

void preOrderPrint(BST *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void BFSnewLine(BST *root){
    if(root == NULL)
        return;
    queue<BST *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front() == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<q.front()->data<<" ";
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }
}

bool searchIT(BST* root, int d){
    if(root == NULL)
        return false;
    if(root->data == d)
        return true;
    if(root->data >= d)
        return searchIT(root->left, d);
    else
        return searchIT(root->right, d);
}

BST* deleteIT(BST* root, int d){
    if(root == NULL)
        return NULL;
    if(root->data == d){
        if(!root->left && !root->right)
            return NULL;
        else if(root->left && !root->right){
            BST* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
            BST* temp = root->left;
            delete root;
            return temp;
        }
        else{
            BST* replaceNode = root->right;
            while(replaceNode->left != NULL){
                replaceNode = replaceNode->left;
            }
            root->data = replaceNode->data;
            root->right = deleteIT(root->right, replaceNode->data);
        }
    }
    else if(root-> data < d)
        root->right = deleteIT(root->right, d);
    else
        root->left = deleteIT(root->left, d);
    return root;
}

bool isBST(BST* root, int l=INT_MIN, int r=INT_MAX){
    if(root == NULL)
        return true;
    if(root->data >= l && root->data<=r && isBST(root->left, l, root->data) && isBST(root->right, root->data, r))
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BST* root = build(); // 3 9 7 1 2 4 8 -1
    cout<<"BFS TRAVERSAL"<<endl;
    BFSnewLine(root);
    cout<<"Node 4 is ";
    if(searchIT(root, 4)) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    deleteIT(root, 3);
    BFSnewLine(root);
    if(isBST(root)) cout<<"IS BST"<<endl;
    else cout<<"IS NOT BST"<<endl;

    return 0;
}
