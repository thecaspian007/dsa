class Solution {
public:
    int calPoints(vector<string>& operations) {
        if(operations.empty()){
            return 0;
        }
        int record = 0;
        stack<int> st;
        for(int i = 0; i<operations.size(); i++){

            if(!st.empty() && operations[i] == "C"){
                st.pop();
            }
            if(!st.empty() && operations[i] == "D"){
                int val = st.top();
                st.push(val*2);
            }
            if(!st.empty() && operations[i] == "+"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);    
                st.push(val1 + val2);
            }
            if(operations[i] != "+" && operations[i] != "D" && operations[i] != "C"){
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty()){
            record = record + st.top();
            st.pop();
        }
        return record;
    }
};