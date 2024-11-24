class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unordered_map<int, int>mp;
        int len = nums.size();

        if(len == 0)
        {
            return 0;
        }

        for(int i = 0; i<len; i++)
        {
            mp[nums[i]]++;
        }

        int k = 0;
        int i = 0;
        for(auto it: mp)
        {
            if(it.first == val)
            {
                k = it.second;
            }
            else
            while(it.second--)
            {
                nums[i] = it.first;
                i++;
            }
        }
        return len-k;
    }
};