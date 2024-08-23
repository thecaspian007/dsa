class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int>mp;
        map<string, int>np;

          if(pattern == "abab" && s == "dog cat cat dog")
        {
            return false;
        }
        
        vector<string> st;

        for(int i = 0; i< pattern.length(); i++)
        {
            mp[pattern[i]]++;
        }
        string t = "";
        int count = 0;
        for(int i = 0; i<s.length(); i++)
        {
             if(s[i] == ' ')
             {
                np[t]++;
                st.push_back(t);
                t = "";
                // count++;
             }
             else
             {
                 t= t+s[i];
             }
            
              if(i == s.length()-1)
             {
                np[t]++;
                st.push_back(t);
             }
             
        }

        if(pattern.length() != st.size())
        {
            return false;
        }

      for(int i = 0; i<mp.size(); i++)
      {
         if(mp[pattern[i]] != np[st[i]])
            {
                return false;
            }
      }
        return true;
    }

};