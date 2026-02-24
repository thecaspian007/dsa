class Solution {
public:
    void combination(vector<int>& candidates, int target, int index, vector<vector<int>>&ans, vector<int>&combo) {
        if(target == 0){
            ans.push_back(combo);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            if(candidates[i] > target){
                return;
            }
            combo.push_back(candidates[i]);
            combination(candidates, target - candidates[i], i, ans, combo);
            combo.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int>>ans;
       vector<int>combo;
       combination(candidates, target, 0, ans, combo);
       return ans;
    }
};