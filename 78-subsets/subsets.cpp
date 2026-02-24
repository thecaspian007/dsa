class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int>&path, vector<vector<int>> &ans) {
        if(index == nums.size()){
            ans.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        dfs(index+1, nums, path, ans);

        path.pop_back();
        dfs(index+1, nums, path, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>path;
        dfs(0, nums, path, ans);
        return ans;
    }
};