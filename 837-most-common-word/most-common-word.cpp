class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(),banned.end());
        unordered_map<string,int> freq;
        string word;
        for(char ch : paragraph)
        {
            if(isalpha(ch))
            {
                word += tolower(ch);
            }
            else
            {
                if(!word.empty())
                {
                    if(!bannedSet.count(word))
                        freq[word]++;

                    word.clear();
                }
            }
        }
        if(!word.empty())
        {
            if(!bannedSet.count(word))
                freq[word]++;
        }
        string ans;
        int mx = 0;
        for(auto &[w,cnt] : freq)
        {
            if(cnt > mx)
            {
                mx = cnt;
                ans = w;
            }
        }
        return ans;
    }
};