class Solution {
public:
    void combination(vector<int>& candidates, int target, int index, vector<vector<int>>&ans, vector<int>&combo) {
        if(target == 0){
            ans.push_back(combo);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1])
            continue;
            
            if(candidates[i] > target){
                return;
            }
            combo.push_back(candidates[i]);
            combination(candidates, target - candidates[i], i+1, ans, combo);
            combo.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int>>ans;
       vector<int>combo;
       combination(candidates, target, 0, ans, combo);
       return ans;
    }
};