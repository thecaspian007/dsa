class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& visited,vector<int>& path, vector<vector<int>>& result) {
    if(path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(visited[i])
            continue;
        if(i > 0 && nums[i] == nums[i-1] && !visited[i-1])
            continue;
        visited[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, visited, path, result);
        path.pop_back();
        visited[i] = false;
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, path, result);
        return result;
    }
};