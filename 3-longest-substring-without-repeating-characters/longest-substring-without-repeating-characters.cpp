class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r=0, ans=0;
        int count[256] = {0};

        while(r<s.length())
        {
            count[s[r]]++;
            while(count[s[r]] >1)
            {
                count[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        } 
        return ans;
    }
};