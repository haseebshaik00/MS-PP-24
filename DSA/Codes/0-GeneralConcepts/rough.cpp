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

BST* insertNode(BST* root, int d){
	if(root == NULL)
		return new BST(d);
	if(root->data < d)
		root->right = insertNode(root->right, d);
	else
		root->left = insertNode(root->left, d);
	return root;
}

BST* build(){
	int n, d;
	cin>>n;
	BST *root = NULL;
	while(n--){
		cin>>d;
		root = insertNode(root, d);
	}
	return root;
}

void preOrderPrint(BST* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

void rangePrint(BST* root, int a, int b){
	if(root == NULL)
		return;
	if(root->data >= a && root->data<=b)
		cout<<root->data<<" ";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		BST* root = build();
		preOrderPrint(root);
		int a, b;
		cin>>a>>b;
		rangePrint(root, a, b);
		cout<<endl;
	}

	return 0;
}
