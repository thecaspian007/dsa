class Solution {
public:                     
    vector<vector<int>> dp;
    int n, m;

    bool solve(int i, int j, string &s, string &p)
    {
        if(j == m)
            return i == n;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool firstMatch = (i < n) && (s[i] == p[j] || p[j] == '.');
        bool ans;
        if(j + 1 < m && p[j + 1] == '*')
        {
            ans = solve(i, j + 2, s, p) || (firstMatch && solve(i + 1, j, s, p));
        }
        else
        {
            ans = firstMatch && solve(i + 1, j + 1, s, p);
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s, p);
    }
};