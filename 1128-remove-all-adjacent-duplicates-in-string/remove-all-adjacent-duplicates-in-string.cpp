class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.length();
        if(len == 0){
            return "";
        }
        string ans;
        stack<char>st;
        for(char ch: s){
            if(!st.empty() && ch == st.top()){
                st.pop();
                continue;
            }
            st.push(ch);
        }

        while(!st.empty()){
            ans = ans+st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};