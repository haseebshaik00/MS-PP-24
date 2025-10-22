#define ll long long int
class Solution {
public:
    // 1D compressed	Linear scan (Kadane variant)	
    // O(n)	O(1)	Track maxHere,minHere; 
    // on a<0 swap; ans=max(ans,maxHere)	
    // Handles sign flips. | ans = max(ans, maxHere).	O
    // ne pass; i = 0→n-1 (forward).
    int maxProduct(vector<int>& nums) {
        ll currMax=nums[0], currMin=nums[0], ans=nums[0];
        for(int i=1; i<nums.size(); ++i){
            ll x = nums[i];
            if(x < 0) swap(currMin, currMax);
            currMax = max(x, currMax * x);
            currMin = min(x, currMin * x);
            ans = max(ans, currMax);
        }
        return ans;
    }
};