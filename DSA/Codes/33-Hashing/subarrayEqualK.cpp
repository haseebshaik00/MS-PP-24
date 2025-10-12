class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int pre=0, ans=0; m[0] = 1;
        for(int i=0; i<nums.size(); ++i){
            pre += nums[i];
            if(m.count(pre-k)) ans += m[pre-k];
            m[pre]++;
        }
        return ans;
    }
};