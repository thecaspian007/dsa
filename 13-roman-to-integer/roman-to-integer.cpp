class Solution {
public:
    int romanToInt(string s) {
        if(s.length() == 0) {
            return 0;
        }
        int ans = 0;
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == 'I' && s[i+1] != 'V' && s[i+1] != 'X'){
                ans += 1;
                continue;
            } else if(s[i] == 'I' && s[i+1] == 'V') {
                ans += 4;
                i++;
                continue;
            } else if(s[i] == 'V') {
                ans += 5;
                continue;
            } else if(s[i] == 'I' && s[i+1] == 'X') {
                ans += 9;
                i++;
                continue;
            } else if(s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C') {
                ans += 10;
                continue;
            } else if(s[i] == 'X' && s[i+1] == 'L') {
                ans += 40;
                i++;
                continue;
            } else if(s[i] == 'L') {
                ans += 50;
                continue;
            } else if(s[i] == 'X' && s[i+1] == 'C') {
                ans += 90;
                i++;
                continue;
            } else if(s[i] == 'C' && s[i+1] != 'M' && s[i+1] != 'D') {
                ans += 100;
                continue;
            } else if(s[i] == 'C' && s[i+1] == 'D') {
                ans += 400;
                i++;
                continue;
            } else if(s[i] == 'D') {
                ans += 500;
                continue;
            } else if(s[i] == 'C' && s[i+1] == 'M') {
                ans += 900;
                i++;
                continue;
            } else if(s[i] == 'M') {
                ans += 1000;
                continue;
            }
        }
        return ans;
    }
};