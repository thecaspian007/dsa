class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();

        map<char, int>mp;

        if(len1 != len2)
        {
            return false;
        }

        for(int i = 0; i< len1; i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto x: mp)
        {
            if(x.second != 0)
            {
                return false;
            }
        }
        return true;

       
        
    }
};