vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int k=0; k<n-2; k++){
            if(k>0 && nums[k-1]==nums[k]) continue;
            int i=k+1, j=n-1;
            while(i<j){
                if(i-1 > k && nums[i-1] == nums[i]) i++;
                else if(j+1<n && nums[j] == nums[j+1]) j--;
                else{
                    int x = nums[i]+nums[j]+nums[k];
                    if(x==0 && i!=j && j!=k && k!=i){
                        ans.push_back({nums[k], nums[i],nums[j]});
                        i++; j--;
                    }
                    else if(x < 0) i++;
                    else j--;
                }
            }
        }
        return ans;
    }