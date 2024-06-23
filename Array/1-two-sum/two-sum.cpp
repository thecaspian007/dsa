class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
        {
            return {};
        }
        
        unordered_map<int, int>mp;
        for(int i = 0; i< len; i++)
        {
           
            int val = target - nums[i];
           
             if(mp.count(val))
                {
                    return {i, mp[val]};
                }
              mp[nums[i]] = i;
            
        }
        return {};
    }
};