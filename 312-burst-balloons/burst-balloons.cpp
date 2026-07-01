class Solution {
public:
     vector<vector<int>> dp;

    int solve(int left,
              int right,
              vector<int>& nums)
    {
        if (left + 1 == right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];
        int ans = 0;
        for (int k = left + 1; k < right; k++) {
            ans = max(ans,
                      solve(left, k, nums) +
                      solve(k, right, nums) +
                      nums[left] * nums[k] * nums[right]);
        }
        return dp[left][right] = ans;
    }


    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int m = nums.size();
        dp.assign(m, vector<int>(m, -1));
        return solve(0, m - 1, nums); 
    }
};