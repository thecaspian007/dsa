class Solution {
public:
    vector<int> getTable(const string &s) {
        vector<int> table(s.length(), 0);
        int index = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[index] == s[i]) {
                index++;
                table[i] = index;
            } else {
                if (index != 0) {
                    index = table[index - 1];
                    i--; 
                } else {
                    table[i] = 0;
                }
            }
        }
        return table;
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        vector<int> table = getTable(temp);

        int longestPrefixLen = table.back();

        string suffix = s.substr(longestPrefixLen);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};
