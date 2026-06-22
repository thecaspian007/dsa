class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if(k > s2.size())
            return false;
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        for(char ch : s1)
            need[ch - 'a']++;
        int left = 0;
        for(int right = 0; right < s2.size(); right++)
        {
            window[s2[right] - 'a']++;
            if(right - left + 1 > k)
            {
                window[s2[left] - 'a']--;
                left++;
            }
            if(right - left + 1 == k)
            {
                if(window == need)
                    return true;
            }
        }
        return false;
    }
};