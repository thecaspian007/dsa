class Solution {
public:
    int numberOfSpecialChars(string word) {
        int len = word.length();
        if(len == 0){
            return 0;
        }
        vector<int>lower(26, -1);
        vector<int>upper(26, -1);
        int count = 0;
        for(int i = 0; i<len; i++){
            if(islower(word[i])){
                lower[word[i]-'a']=i;
            }
            else{
                if(upper[word[i]-'A'] == -1) {
                    upper[word[i]-'A'] = i;
                }
            }
        }
        for(int i = 0; i<26; i++){
            if( lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]){
                count++;
            }
        }
        return count;
    }
};