class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int spaces = 0;
        int n = text.size();
        int i = 0;
        while(i < n)
        {
            if(text[i] == ' ')
            {
                spaces++;
                i++;
            }
            else
            {
                string word;
                while(i < n && text[i] != ' ')
                {
                    word += text[i];
                    i++;
                }
                words.push_back(word);
            }
        }
        if(words.size() == 1)
        {
            return words[0] + string(spaces, ' ');
        }
        int gap = spaces / (words.size() - 1);
        int extra = spaces % (words.size() - 1);
        string ans;
        for(int i = 0; i < words.size(); i++)
        {
            ans += words[i];
            if(i != words.size() - 1)
            {
                ans += string(gap, ' ');
            }
        }
        ans += string(extra, ' ');
        return ans;
    }
};