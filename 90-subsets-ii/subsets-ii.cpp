class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int>&path, vector<vector<int>> &ans) {
        ans.push_back(path);
        for(int i = index; i< nums.size(); i++){
            if(i>index && nums[i] == nums[i-1]){
                continue;
            }
        path.push_back(nums[i]);
        dfs(i+1, nums, path, ans);
        path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>path;
        sort(nums.begin(), nums.end());
        dfs(0, nums, path, ans);
        return ans;
    }
};