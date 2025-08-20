#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class BTN{
public:
    int val;
    BTN *left;
    BTN *right;

    BTN(int d){
        val = d;
        left = right = nullptr;
    }
};

BTN* insertNode(BTN* root, int d){
    if(!root) return new BTN(d);
    if(d < root->val) root->left = insertNode(root->left, d);
    else root->right = insertNode(root->right, d);
    return root;
}

BTN* buildTree(){
    int d;
    cin>>d;
    BTN *root = nullptr;
    while(d!=-1){
        root = insertNode(root, d);
        cin>>d;
    }
    return root;
}

bool searchTree(BTN *root, int key){
    if(!root) return false;
    if(key == root->val) return true;
    if(key < root->val) return searchTree(root->left, key);
    else return searchTree(root->right, key);
}

void printTree(BTN* root){
    if(!root) return;
    printTree(root->left);
    cout<<root->val<<" ";
    printTree(root->right);
}

BTN* deleteNode(BTN *root, int key){
    if(!root) return root;
    if(key == root->val){
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        else if(!root->right){
            BTN* temp = root->left;;
            delete root;
            return temp;
        }
        else if(!root->left){
            BTN* temp = root->right;;
            delete root;
            return temp;
        }
        else{
            BTN *newNode = root->right;
            while(newNode->left)
                newNode = newNode->left;
            root->val = newNode->val;
            root->right = deleteNode(root->right, newNode->val);
            return root;
        }
    }
    if(key < root->val) root->left = deleteNode(root->left, key);
    else root->right = deleteNode(root->right, key);
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // insert
    BTN *root = buildTree();
    // print
    printTree(root);
    cout<<endl;
    // search
    if(searchTree(root, 5)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    // delete
    if(searchTree(root, 10)){
        root = deleteNode(root, 10);
        printTree(root);
        cout<<endl;
    }
    else cout<<"Can't find Node!";

    return 0;
}