class Solution {
public:
    string reverseWords(string s) {
        string ans;
        if(s.length() == 0){
            return "";
        }
        string res;
        int i = 0;
        for(char ch : s){
            if(ch == ' '){
                reverse(res.begin(), res.end());
                ans = ans+ res;
                if(i != s.length() -1){
                    ans = ans + ' ';
                }
                res = "";
                i++;
                continue;
            }
            res = res+ch;
            i++;
        }
        reverse(res.begin(), res.end());
        ans = ans+ res;
        return ans;
    }
};