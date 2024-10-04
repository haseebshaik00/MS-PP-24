class Node{
public:
    Node* left;
    Node* right;

    Node(){
        left = NULL;
        right = NULL;
    }
};

class Trie{
public:
    Node* root;
    int maxXor=0;

    Trie(){
        root = new Node();
    }

    void insert(int a){
        Node* temp = root;
        for(int i=31; i>=0; i--){
            int c = (a>>i) & 1;
            if(c){
              if(!temp->right)
                temp->right = new Node();
              temp=temp->right;
            }
            else{
                if(!temp->left)
                    temp->left = new Node();
                temp= temp->left;
            }
        }
        maxXor= max(maxXor, maxi(a));
    }

    int maxi(int a){
        int ans = 0;
        Node* temp = root;
        for(int i=31; i>=0; i--){
            int c = (a>>i) & 1;
            if(c){
              if(temp->left){
                ans += (1<<i);
                temp = temp->left;
              }
              else
              temp=temp->right;
            }
            else{
                if(temp->right){
                    ans += (1<<i);
                    temp = temp->right;
                }
                else
                temp= temp->left;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        for(auto x:nums)
            t->insert(x);
        return t->maxXor;
    }
};