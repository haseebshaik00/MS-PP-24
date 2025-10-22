class Solution {
public:
    // 1D	Linear prefix with dictionary	O(n²)	O(n)	
    // dp[i]=any(dp[j] && s[j:i]∈dict)	HashSet dict; optional Trie to prune.	
    // Bottom-up; i = 1→n; inner j < i.
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        unordered_set<int> len;
        int n = s.length();
        vector<bool> dp(n+1, false); dp[0] = true;
        for(auto &x: wordDict){
            words.insert(x);
            len.insert(x.length());
        }
        for(int i=1; i<=n; ++i){
            for(auto &x: len){
                if(x > i) continue;
                if(!dp[i-x]) continue; // valid substring means till 0 to i-x dp is true
                if(words.count(s.substr(i-x, x))){ // substring check if present in dict
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};