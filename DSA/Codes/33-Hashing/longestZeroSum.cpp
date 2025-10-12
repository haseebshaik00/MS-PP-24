class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> lastIdx;
        int pre=0, ans=0; lastIdx[0] = -1;
        for(int i=0; i<arr.size(); ++i){
            pre += arr[i];
            if(lastIdx.count(pre)) ans = max(ans, i-lastIdx[pre]);
            else lastIdx[pre] = i;
        }
        return ans;
    }
};