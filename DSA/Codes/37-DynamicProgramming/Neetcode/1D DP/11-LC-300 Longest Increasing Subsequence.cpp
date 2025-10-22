class Solution {
public:
    // 1D (or tails)	Linear prefix	
    // O(n²) or O(n log n)	O(n)	
    // DP: dp[i]=1+max(dp[j]) for a[j]<a[i]
    // Faster “tails” uses lower_bound (not classic DP).	
    // Bottom-up; i = 0→n-1; inner j < i.

    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(auto &x: nums){
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if(it == temp.end()) temp.push_back(x);
            else *it = x;
        }
        return temp.size();
    }
};