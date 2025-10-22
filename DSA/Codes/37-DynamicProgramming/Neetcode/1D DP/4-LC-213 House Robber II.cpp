class Solution {
public:
    // 1D compressed	Linear prefix on two ranges	
    // O(n)	O(1)	max(rob(0..n-2), rob(1..n-1))	
    // Edge cases n=1,2.	
    // Bottom-up; run 198 on ranges with i forward.
    int robRange(vector<int> &nums, int i, int j){
        int prev1=0, prev2=0;
        for(int k=i; k<=j; ++k){
            int curr = max(prev2 + nums[k], prev1);
            prev2 = prev1;
            prev1=curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }
};