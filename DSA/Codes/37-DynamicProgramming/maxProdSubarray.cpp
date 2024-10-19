class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long int currMin=nums[0], currMax=nums[0], ans=nums[0];
        for(int i=1; i<n; i++){
            long int temp = max({nums[i]*1L, nums[i] * currMax, nums[i] * currMin});
            currMin = min({nums[i]*1L, nums[i] * currMax, nums[i] * currMin});
            currMax = temp;
            ans = max(ans, max(currMax, currMin));
        }
        return ans;
    }
};