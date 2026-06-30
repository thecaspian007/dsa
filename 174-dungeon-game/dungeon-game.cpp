class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                }
                else
                {
                    int down = INT_MAX;
                    int right = INT_MAX;
                    if (i + 1 < m)
                        down = dp[i + 1][j];
                    if (j + 1 < n)
                        right = dp[i][j + 1];
                    int need = min(down, right);
                    dp[i][j] = max(1, need - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};