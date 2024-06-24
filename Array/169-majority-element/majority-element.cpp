class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        if(len == 0)
        {
            return -1;
        }
        // int mx = INT_MIN;
        // int count = 0;
        unordered_map<int, int>mp;

        for(int i = 0; i< len; i++)
            {
                mp[nums[i]]++;
            }
       
       for(int i = 0; i< len; i++)
       {
            if(mp[nums[i]] > len/2)
            {
                count = nums[i];
            }
       }
       return count;
    }
};