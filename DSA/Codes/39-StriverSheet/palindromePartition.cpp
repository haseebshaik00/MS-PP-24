class Solution {
public:
    void doPart(vector<vector<string>> &ans, vector<string> &v, const string &s, const int n, int index){
        if(index == n){
            ans.push_back(v);
            return;
        }
        for(int i=index; i<n; i++){
            if(isPalindrome(index, i, s)){
                v.push_back(s.substr(index, i-index+1));
                doPart(ans, v, s, n, i+1);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(int s, int e, const string &str){
        for(; s<=e; s++, e--){
            if(str[s] != str[e])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        int n = s.length();
        doPart(ans, v, s, n, 0);
        return ans;
    }
};