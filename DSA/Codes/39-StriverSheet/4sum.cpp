class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n= nums.size();
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            for(int j=n-1; j>i+2; j--){
                if (j<n-1 && nums[j] == nums[j+1]) continue;
                int a=i+1, b=j-1;
                long long int x = (target*1LL-nums[i]*1LL-nums[j]*1LL), y=0;
                while(a<b){
                    y = (nums[a]+nums[b]) * 1LL;
                    if(y == x){
                        ans.push_back({nums[i], nums[a], nums[b], nums[j]});
                        while (a < b && nums[a] == nums[a + 1]) a++;
                        while (a < b && nums[b] == nums[b - 1]) b--;
                        a++;
                        b--;
                    }
                    else if(y<x) a++;
                    else b--;
                }
            }
        }
        return ans;
    }
};