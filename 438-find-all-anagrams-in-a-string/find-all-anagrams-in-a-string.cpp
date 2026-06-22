class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         vector<int> ans;
        int k = p.size();
        if(k > s.size())
            return ans;
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        for(char ch : p)
            need[ch - 'a']++;
        int left = 0;
        for(int right = 0; right < s.size(); right++)
        {
            window[s[right] - 'a']++;
            if(right - left + 1 > k)
            {
                window[s[left] - 'a']--;
                left++;
            }
            if(right - left + 1 == k)
            {
                if(window == need)
                {
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};