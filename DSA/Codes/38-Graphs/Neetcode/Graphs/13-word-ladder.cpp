// O(n^2 * m)
class Solution {
public:
    bool wordMatch(string a, string b){
        int cnt=0;
        for(int i=0; i<a.length(); ++i)
            if(a[i]!=b[i]) cnt++;
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) 
            wordList.push_back(beginWord);
        int n = wordList.size(), ans=1;
        unordered_map<string, vector<string>> graph;
        for(auto &x: wordList) 
            for(auto &y: wordList)
                if(x!=y && wordMatch(x, y)) graph[x].push_back(y);
        queue<string> q; 
        unordered_set<string> visited; 
        bool flag = false;
        q.push(beginWord);
        visited.insert(beginWord);
        q.push("");
        while(!q.empty()){
            auto x = q.front(); q.pop();
            if(x == ""){
                if(q.empty()) break;
                q.push("");
                ++ans;
                continue;
            }
            for(auto &y: graph[x]){
                if(y==endWord) return ++ans;
                if(!visited.count(y)) q.push(y);
                visited.insert(y);
            }
        }
        return 0;
    }
};

// O(n*m*26)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.length(), ans=1;
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.count(endWord)) return 0;
        words.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string x = q.front(); q.pop();
                if(x == endWord) return ans;
                for(int i=0; i<L; ++i){
                    char ch = x[i];
                    for(char j='a'; j<='z'; ++j){
                        x[i] = j;
                        if(words.count(x)){
                            q.push(x);
                            words.erase(x);
                        }
                    }
                    x[i]=ch;
                }
            }
            ++ans;
        }
        return 0;
    }
};