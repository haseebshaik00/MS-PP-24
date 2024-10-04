#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    bool terminal;
    char data;
    int occ;
    unordered_map<char, TrieNode*> m;

    TrieNode(char ch){
        terminal = false;
        data = ch;
        occ = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    int cnt;

    Trie() {
        root = new TrieNode('\0');
        cnt = 0;
    }

    void insert(string word) {
        int n = word.length();
        TrieNode* temp = root;
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(!temp->m.count(ch))
                temp->m[ch] = new TrieNode(ch);
            temp = temp->m[ch];
            temp->occ++;
        }
        temp->terminal = true;
        cnt++;
    }

    bool search(string word) {
        if(cnt == 0)
            return false;
        TrieNode* temp = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(!temp->m.count(ch))
                return false;
            temp = temp->m[ch];
        }
        return temp->terminal;
    }

    bool startsWith(string prefix) {
        if(cnt == 0)
            return false;
        if(prefix == "")
            return true;
        TrieNode* temp = root;
        int n = prefix.length();
        for(int i=0; i<n; i++){
            char ch = prefix[i];
            if(!temp->m.count(ch))
                return false;
            temp = temp->m[ch];
        }
        return true;
    }

    // smallest unique prefix
    string isUnique(string word){
        int n = word.length(), i=0;
        TrieNode* temp = root;
        for(; i<n; i++){
            char ch = word[i];
            if(temp->m.count(ch) == 0)
                break;
            temp=temp->m[ch];
        }
        return word.substr(0, i+1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie* obj = new Trie();
    string word = "apple", prefix = "app";
    obj->insert(word);
    obj->insert("ball");
    obj->insert("batman");
    obj->insert("app");
    obj->insert("crow");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->startsWith(prefix);
    cout<<param_2<<" "<<param_3<<" "<<obj->isUnique("ballet")<<endl;

    return 0;
}
