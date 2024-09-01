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

class PairDiameter{
public:
    int height;
    int diameter;

    PairDiameter(){
        height=0;
        diameter=0;
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
    postOrderPrint(root->right);
    cout<<root->data<<" ";
}

int height(BTN *root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void printKthLevel(BTN *root, int k){
    if(root == NULL)
        return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}

void levelOrderPrint(BTN *root){
    if(root == NULL)
        return;
    int h = height(root);
    for(int i=0; i<h; i++){
        printKthLevel(root, i);
        cout<<endl;
    }
}

void BFS(BTN *root){
    if(root == NULL)
        return;
    queue<BTN *> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left != NULL) q.push(q.front()->left);
        if(q.front()->right != NULL) q.push(q.front()->right);
        q.pop();
    }
}

void BFSnewLine(BTN *root){
    if(root == NULL)
        return;
    queue<BTN *> q;
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

void countNodesAndSum(BTN *root, int &n, int &s){
    if(root == NULL)
        return;
    n++;
    s += root->data;
    countNodesAndSum(root->left, n, s);
    countNodesAndSum(root->right, n, s);
}

int diameter(BTN *root){
    if(root == NULL)
        return 0;
    int a = height(root->left) + height(root->right);
    int b = diameter(root->left);
    int c = diameter(root->right);
    return max(a, max(b, c));
}

PairDiameter diameterON(BTN *root){
    PairDiameter p;
    if(root == NULL){
        return p;
    }
    PairDiameter leftP = diameterON(root->left);
    PairDiameter rightP = diameterON(root->right);
    // avoided the O(N^2) complexity of height calculation for n nodes, instead
    // doing the height calculation in class object
    p.height = max(leftP.height, rightP.height)+1;
    p.diameter = max(leftP.height + rightP.height, max(leftP.diameter, rightP.diameter));
    return p;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BTN *root = preorderBuild();
    preOrderPrint(root); cout<<endl;
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    inOrderPrint(root); cout<<endl;
    postOrderPrint(root); cout<<endl;
    cout<<height(root)<<endl;
    printKthLevel(root, 3); cout<<endl;
    levelOrderPrint(root); cout<<endl;
    BFS(root); cout<<endl;
    BFSnewLine(root);
    int noOfNodes=0, nodeSum=0;
    countNodesAndSum(root, noOfNodes, nodeSum);
    cout<<"No. of Nodes= "<<noOfNodes<<" "<<"Node Sum= "<<nodeSum<<endl;
    cout<<diameter(root)<<endl;
    PairDiameter p = diameterON(root);
    cout<<p.height<<" "<<p.diameter<<endl;

    return 0;
}
