class Solution {
public:
    void backtrack(string &s, int start, vector<string>& path, vector<vector<string>>& result,
vector<vector<bool>>& dp) {
        if(start == s.length()) {
            result.push_back(path);
            return;
        }
        for(int end = start; end < s.length(); end++) {
            if(dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, result, dp);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> result;
        vector<string> path;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] &&
                   (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }
        backtrack(s, 0, path, result, dp);
        return result;
    }
};