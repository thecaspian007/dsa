class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for (char ch : s) {
            if (ch == '(') {
                st.push("(");
            }
            else {
                int sum = 0;
                while (!st.empty() && st.top() != "(") {
                    sum += stoi(st.top());
                    st.pop();
                }
                st.pop();
                if (sum == 0)
                    st.push("1");          
                else
                    st.push(to_string(2 * sum));
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};