#include <iostream>
using namespace std;

class node {
public :
    int noOfChildren ;
    int data ; 
    node(int d,int n) {
        data = d ;
        noOfChildren = n ;
        right = left = NULL ; 
    }
    node *right ;
    node *left ;
};


//Generic Tree Input
//Used in problem - Sum at level k
node* buildTreeGeneric(node*root){
    int d,n ;
    cin >> d >> n;
    root = new node(d,n);
    if(n==0){
        return root ; 
    }
    else if(n==1){
        root->left = buildTreeGeneric(root->left);
        return root ;
    }
    else {
        root->left = buildTreeGeneric(root->left);
        root->right = buildTreeGeneric(root->right) ; 
        return root ;
    }
}

void sumAtKthLevel(node* root, int k, int i, int &sum){
	if(root == NULL)
		return;
	if(i==k)
		sum += root->data;
	sumAtKthLevel(root->left, k, i+1, sum);
	sumAtKthLevel(root->right, k, i+1, sum);
}

int main() {
    node *root = NULL;

    //Generic Tree Input 
    root = buildTreeGeneric(root);          
	int k;
	cin>>k;
	int sum=0;
	sumAtKthLevel(root,k, 0, sum);
	cout<<sum<<endl;

    return 0;
}
