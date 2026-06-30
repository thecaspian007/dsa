class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    int down = (i + 1 < m) ? dp[i + 1][j] : 1e9;
                    int right = (j + 1 < n) ? dp[i][j + 1] : 1e9;
                    dp[i][j] = grid[i][j] + min(down, right);
                }
            }
        }
        return dp[0][0];
    }
};