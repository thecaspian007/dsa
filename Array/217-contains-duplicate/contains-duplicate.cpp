class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        map<int, int>mp;
        for(int i = 0; i<len; i++)
        {
            mp[nums[i]]++;
        }

        for(int i = 0; i<len; i++)
        {
            if(mp[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};