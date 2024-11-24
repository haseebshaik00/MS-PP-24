class Solution {
public:
    vector<vector<int>> ans;
    int n;
    vector<int> v;

    void calSum(const vector<int>& candidates, int target, int index){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i=index; i<n; i++){
            if(candidates[i] > target) break;
            v.push_back(candidates[i]);
            calSum(candidates, target-candidates[i], i);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        calSum(candidates, target, 0);
        return ans;
    }
};