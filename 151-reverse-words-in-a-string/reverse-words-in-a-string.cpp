class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;
        while(i < n)
        {
            while(i < n && s[i] == ' ')
                i++;
            if(i >= n)
                break;
            string word;
            while(i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            words.push_back(word);
        }
        string ans;
        for(int i = words.size() - 1; i >= 0; i--)
        {
            ans += words[i];
            if(i != 0)
                ans += " ";
        }
        return ans;
    }
};