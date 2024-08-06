class Solution {
public:
 bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

      void solve(string s, int start, vector<string> &substr, vector<vector<string>> &ans) {
        if (start == s.length()) {
            ans.push_back(substr);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                substr.push_back(s.substr(start, i - start + 1));
                solve(s, i + 1, substr, ans);
                substr.pop_back();  // Backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>> ans;
        vector<string> substr;
        solve(s, 0, substr, ans);
        return ans;
    }
};