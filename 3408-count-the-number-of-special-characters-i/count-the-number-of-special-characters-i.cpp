class Solution {
public:
    int numberOfSpecialChars(string word) {
        int len = word.length();
        if(len == 0){
            return 0;
        }
        unordered_map<int, int>mp;
        int count = 0;
        for(auto i : word){
            int val = i;
            mp[i]++;
        }
        for(auto i : mp){
          if(mp.find(i.first + 32) != mp.end()){
            count++;
          }
        }
        return count;
    }
};