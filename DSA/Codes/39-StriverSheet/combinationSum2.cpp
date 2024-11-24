class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int n;

    void calSum(vector<int>& candidates, int target, int index){
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if (index == n || candidates[index] > target) return;
        for (int i = index; i < n; ++i) {
            if(candidates[i] > target) break;
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            v.push_back(candidates[i]);
            calSum(candidates, target - candidates[i], i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        calSum(candidates, target, 0);
        return ans;
    }
};