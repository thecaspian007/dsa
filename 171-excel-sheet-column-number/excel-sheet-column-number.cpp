class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int len = columnTitle.length();
        for(char c : columnTitle)
        {
            int val = c - 'A' + 1;
            ans = ans*26 + val;
        }
        return ans;
    }
};