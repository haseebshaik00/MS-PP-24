int removeDuplicates(vector<int>& nums) {
        int ans=-101, n=nums.size(), count=0, j=0;
        for(int i=0; i<n; i++){
            if(nums[i] > ans){
                ans = nums[i];
                nums[j] = ans;
                j++;
                count++;
            }
        }
        return count;
    }