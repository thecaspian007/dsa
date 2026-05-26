class Solution {
public:
    int numberOfSpecialChars(string word) {
        int len = word.length();
        if(len == 0){
            return 0;
        }
        vector<int>lower(26, 0);
        vector<int>upper(26, 0);
        int count = 0;
        for(auto i : word){
            if(i>=97){
                lower[i-'a'] = 1;
            }
            else{
                upper[i-'A'] = 1;
            }
        }
        for(int i = 0; i<26; i++){
          if(lower[i] && upper[i]){
            count++;
          }
        }
        return count;
    }
};