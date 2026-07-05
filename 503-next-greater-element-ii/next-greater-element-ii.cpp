class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int len = nums.size();
        if(len == 0)
        {
            return ans;
        }
        stack<int>st;
        
        for(int i = 2*len-1; i>len-1; i--)
        {
            int k = i%len;
            if(st.empty())
            {
                
                st.push(nums[k]);
            }
            else if (st.top()< nums[k])
            {
                st.pop();
                i++;
            }
            else
            {
                st.push(nums[k]);
            }
        }

        for(int i = len-1; i>=0; i--)
        {
             if(st.empty())
            {
                
                st.push(nums[i]);
                ans.push_back(-1);
            }
            else if(st.top() > nums[i])
            {
                ans.push_back(st.top());
                st.push(nums[i]);
            }
            else
            {
                st.pop();
                i++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};