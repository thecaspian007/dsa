class Solution {
public:
    string processStr(string s) {
        int len = s.length();
        if(len == 0){
            return "";
        }
        string ans;
        for(char ch: s){
            int val = ch;
            if(val>=97 && val<=122){
                ans = ans + ch;
            }
            else if(ch == '#'){
                ans = ans + ans;
            }
            else if(ch == '%' && !ans.empty()){
                reverse(ans.begin(), ans.end());
            }
            else if(ch == '*' && !ans.empty()){
                ans.pop_back();
            }
        }
        return ans;
    }
};