class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total)
            return 0;
        if ((target + total) % 2)
            return 0;
        int required = (target + total) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(required + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= required; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (nums[i - 1] <= j)
                {
                    dp[i][j] +=
                        dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][required]; 
    }
};