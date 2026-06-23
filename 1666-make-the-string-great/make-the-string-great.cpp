class Solution {
public:
    string makeGood(string s) {
        string ans;
        int len = s.length();
        if(len == 0){
            return ans;
        }
        stack<char>st;
        for(char ch: s){
            if(!st.empty() && abs(ch - st.top()) == 32){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};