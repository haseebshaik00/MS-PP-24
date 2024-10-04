#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    int data;
    bool terminal;
    unordered_map<char, TrieNode*> charArr;

    TrieNode(int d){
        data = d;
        terminal = false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}