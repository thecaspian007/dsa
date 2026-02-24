class Solution {
public:
    void combination(int k, int target, int index, vector<vector<int>>&ans, vector<int>&combo) {
        if(combo.size() == k){
            if(target == 0){
                ans.push_back(combo);
                return;
            }
        }
        for(int i = index; i<=9; i++){
            if(i > target){
                return;
            }
            combo.push_back(i);
            combination(k, target - i, i+1, ans, combo);
            combo.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans;
       vector<int>combo;
       combination(k, n, 1, ans, combo);
       return ans;
    }
};