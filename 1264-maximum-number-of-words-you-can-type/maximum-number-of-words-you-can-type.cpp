class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        if(text.length() == 0) {
            return 0;
        }
        vector<int>ch(26,0);
        for(char c : brokenLetters) {
            ch[c - 'a'] = 1;
        }
        int flag = 0, ans = 0;
        for(int i = 0; i< text.length(); i++) {
            if(text[i] == ' ') {
                if(flag == 0) {
                    ans++;
                }
                flag = 0;
            } else if(ch[text[i] - 'a'] == 1) {
                flag = 1;
            }
        }
        if(flag == 0) {
            ans++;
        }
        return ans;
    }
};