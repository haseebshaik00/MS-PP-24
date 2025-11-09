class Solution {
public:
    // POST ORDER DFS!
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> state;
    int n=0; bool flag=true; string order="";

    bool fillGraph(vector<string>& words){
        for(int i=0; i<n; ++i){
            for(auto &x: words[i]){
                if(!state.count(x)){
                    state[x]=0;
                    graph[x]=unordered_set<char>();
                }
            }
        }
        for(int i=0; i<n-1; ++i){
            string a = words[i], b=words[i+1];
            int m = min(a.length(), b.length()), k=0;
            while(k<m && a[k] == b[k]) ++k;
            if(k==m){
                if(a.size() > b.size()) return false;
                else continue;
            }
            graph[a[k]].insert(b[k]);
        }
        return true;
    }

    bool dfs(char u){
        state[u] = 1;
        for(auto &v: graph[u]){
            if(state[v] == 1) return false;
            if(!state[v]) if(!dfs(v)) return false;
        }
        state[u] = 2;
        order.push_back(u);
        return true;
    }
    
    string foreignDictionary(vector<string>& words) {
        n=words.size();
        if(!fillGraph(words)) return "";
        for(auto it=state.begin(); it!=state.end(); ++it){
            if(!it->second){
                if(!dfs(it->first)) return "";
                if(!flag) return "";
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
