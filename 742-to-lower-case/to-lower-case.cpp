class Solution {
public:
    bool isCapital(char ch){
        int val = ch;
        if(val >= 65 && val<=90){
            return true;
        }
        return false;
    }

    string toLowerCase(string s) {
        if(s.length() == 0){
            return "";
        } 
        for (int i = 0; i<s.length(); i++){
            if(isCapital(s[i])){
                int val = s[i];
                s[i] = char(val + 32); 
            }
        }
        return s;
    }
};