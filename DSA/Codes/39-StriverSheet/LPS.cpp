class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), maxLen=1, start=0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start=i;
                maxLen = 2;
            }
        }
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j = i + k - 1;
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    if(k>maxLen){
                        maxLen=k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), maxLen=1, start=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=1; j++){
                int low = i, high=i+j;
                while(low>=0 && high<n && s[low] == s[high]){
                    if(high-low+1 > maxLen){
                        start=low;
                        maxLen = high-low+1;
                    }
                    low--;
                    high++;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};