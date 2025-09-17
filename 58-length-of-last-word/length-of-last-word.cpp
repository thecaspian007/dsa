class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        int count = 0;
        if(len == 1 && s[0] != ' ') {
            return 1;
        }
        for(int i = len-1; i>=0; i--) {
            if(s[i] == ' ' && i ==len-1 || s[i] == ' ' && s[i+1] == ' ') {
                continue;
            }
            if(s[i] == ' ' && s[i+1] != ' ') {
                return count;
            }
            count++;
        }
        return count;
    }
};