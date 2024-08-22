class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();

        if(len == 0)
        {
            return 0;
        }
        int flag = 0;
        int count = 0;
        for(int i = len-1; i>=0; i--)
        {
            if(s[i] == ' ' && flag == 0)
            {
                continue;
            }
            else if (s[i] == ' ' && flag == 1)
            {
                return count;
            }
            else
            {
                count++;
                flag = 1;
            }
        }
        return count;
    }
};