class Solution {
public:
    // 1D compressed	Linear prefix	
    // O(n)	O(1)	dp[i]+= (valid1)*dp[i-1] + (valid2)*dp[i-2]	
    // Handle zeros carefully; valid2 if 10..26.	
    // Bottom-up; i = 1→n (forward).
    int numDecodings(string s) {
        int n = s.length();
        if(!n || s[0]=='0') return 0;
        int prev1=1, prev2=1;
        for(int i=2; i<=n; ++i){
            int curr = 0, twoDigits = (s[i-2]-'0') * 10 + s[i-1]-'0';
            if(s[i-1] != '0') curr += prev1;
            if(twoDigits >= 10 && twoDigits <=26) curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};