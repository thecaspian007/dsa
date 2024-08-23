class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        map<char, int>mp;
        map<char, int>np;

        vector<int> indexS(200, 0); 
        vector<int> indexT(200, 0);

        if(len1 != len2)
        {
            return false;
        }

         for(int i = 0; i < len1; i++) {
            if(indexS[s[i]] != indexT[t[i]]) { 
                return false; 
            }
            
            indexS[s[i]] = i + 1; 
            indexT[t[i]] = i + 1;
        }
        return true;
    }
};