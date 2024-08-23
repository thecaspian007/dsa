class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        map<char, int>mp;

        if(len1>len2)
        {
            return false;
        }

        for(int i = 0; i<len2; i++)
        {
            mp[magazine[i]]++;
        }

        for(int i = 0; i<len1; i++)
        {
            mp[ransomNote[i]]--;
            if(mp[ransomNote[i]] >=0)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};