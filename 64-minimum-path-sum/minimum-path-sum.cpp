class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (i >= m || j >= n)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = solve(i + 1, j, grid);
        int right = solve(i, j + 1, grid);
        return dp[i][j] = grid[i][j] + min(down, right);
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));
        return solve(0, 0, grid);
    }
};