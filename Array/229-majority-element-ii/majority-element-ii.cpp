class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans;
        map<int, int>mp;
        set<int>st;
        if(len == 0)
        {
            return ans;
        }
        for(int i = 0; i<len; i++)
        {
            st.insert(nums[i]);
        }

        for(int i = 0; i<len; i++)
        {
            mp[nums[i]]++;
        }

        for(auto it: st)
        {
             if(mp[it] > len/3)
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};