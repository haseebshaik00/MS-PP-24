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
