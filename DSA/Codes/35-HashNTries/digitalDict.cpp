#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	char ch;
	bool terminal;
	map<char, TrieNode*> m;

	TrieNode(char c){
		ch = c;
		terminal = false;
	}
};

class Trie{
public:
	TrieNode* root;

	Trie(){
		root = new TrieNode('\0');
	}

	void insert(string word){
		int n=word.length();
		TrieNode *temp = root;
		for(int i=0; i<n; i++){
			char ch = word[i];
			if(temp->m.find(ch) == temp->m.end()){
				temp->m[ch] = new TrieNode(ch);
			}
			temp = temp->m[ch];
		}
		temp->terminal = true;
	}

	void print(TrieNode *temp, string s, vector<string> &v){
		if(temp->terminal)	
			v.push_back(s);
		for(auto it : temp->m){
			s.push_back(it.first);
			print(it.second, s, v);
			s.pop_back();
		}
	}

	bool search(string word, vector<string> &v){
		int n=word.length();
		TrieNode *temp = root;
		string s = "";
		for(int i=0; i<n; i++){
			char ch = word[i];
			if(temp->m.find(ch) == temp->m.end()){
				insert(word);
				return false;
			}
			else{
				s.push_back(ch);
				temp = temp->m[ch];
			}
		}
		print(temp, s, v);
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin>>n;
	cin.ignore();
	Trie *root = new Trie();
	for(int i=0; i<n; i++){
		string s;
		getline(cin, s);
		root->insert(s);
	}
	cin>>q;
	cin.ignore();
	for(int i=0; i<q; i++){
		string s;
		getline(cin, s);
		vector<string> v;
		if(!(root->search(s, v))){
			cout<<"No suggestions"<<endl;
			continue;
		}
			for(auto it:v)
				cout<<it<<endl;
			v.clear();
	}

	return 0;
}