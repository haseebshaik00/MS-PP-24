#include<bits/stdc++.h>
using namespace std;

class BTN{  
public:
    int data;
    BTN *left;
    BTN *right;

    BTN(int d){
        data=d;
        left = NULL;
        right = NULL;
    }
};

BTN* preorderBuild(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    BTN *root = new BTN(d);
    root->left = preorderBuild();
    root->right = preorderBuild();
    return root;
}

void preOrderPrint(BTN *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void inOrderPrint(BTN *root){
    if(root == NULL)
        return;
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

void postOrderPrint(BTN *root){
    if(root == NULL)
        return;
    postOrderPrint(root->left);
    cout<<root->data<<" ";
    postOrderPrint(root->right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BTN *root = preorderBuild();
    preOrderPrint(root);
    cout<<endl;
    inOrderPrint(root);
    cout<<endl;
    postOrderPrint(root);
    cout<<endl;

    return 0;
}