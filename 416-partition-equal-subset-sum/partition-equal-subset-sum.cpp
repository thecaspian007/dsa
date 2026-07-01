class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int index, int target, vector<int>& nums)
    {
        if (target == 0)
            return true;
        if (index == nums.size())
            return false;
        if (dp[index][target] != -1)
            return dp[index][target];
        bool skip = solve(index + 1, target, nums);
        bool take = false;
        if (nums[index] <= target)
            take = solve(index + 1, target - nums[index], nums);
        return dp[index][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum / 2;
        dp.assign(nums.size(), vector<int>(target + 1, -1));
        return solve(0, target, nums);
    }
};