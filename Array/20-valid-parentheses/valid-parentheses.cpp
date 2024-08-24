class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len == 0)
        {
            return false;
        }

        stack<char>st;

        for(int i = 0; i<len; i++)
        {
            if(st.empty())
            {
                 st.push(s[i]);
            }
            else if(st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}')
            {
                st.pop();
            }
            else
            {
                 st.push(s[i]);
            }
           
        }

        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};