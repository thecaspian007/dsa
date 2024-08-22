class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        vector<int> val;
        int sum = 0;
        if(s.size() == 0)
        {
            return 0;
        }
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        for(int i = 0; i<s.size(); )
        {
            if(s[i] == 'I' && s[i+1] == 'V')
            {
                val.push_back(4);
                i = i+2;
            }
            else if(s[i] == 'I' && s[i+1] == 'X')
            {
                val.push_back(9);
                i = i+2;
            }
            else if(s[i] == 'X' && s[i+1] == 'C')
            {
                val.push_back(90);
                i = i+2;
            }
            else if(s[i] == 'X' && s[i+1] == 'L')
            {
                val.push_back(40);
                i = i+2;
            }
            else if(s[i] == 'C' && s[i+1] == 'M')
            {
                val.push_back(900);
                i = i+2;
            }
            else if(s[i] == 'C' && s[i+1] == 'D')
            {
                val.push_back(400);
                i = i+2;
            }
            else
            {
                 val.push_back(mp[s[i]]);
                 i++;
            }
           
        }

        for(int i = 0; i<val.size(); i++)
        {
            sum += val[i];
        }
        return sum;
    }
};