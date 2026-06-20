class Solution {
public:
    bool containsVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    bool isVowel(string word){
        int len = word.length();
        if(len == 0){
            return false;
        }
        if(containsVowel(word[0]) && containsVowel(word[len-1])){
            return true;
        }
        return false;
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        if(words.size() == 0){
            return 0;
        }
        int count = 0;
        for (int i = left; i<= right; i++){
            if(isVowel(words[i])){
                count++;
            }
        }
        return count;
    }
};