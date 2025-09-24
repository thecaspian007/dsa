class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int lastSeenS[256] = {0};
        int lastSeenT[256] = {0};
        for(int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if(lastSeenS[c1] != lastSeenT[c2]) return false;
            lastSeenS[c1] = i + 1;
            lastSeenT[c2] = i + 1;
        }
        return true;
    }
};