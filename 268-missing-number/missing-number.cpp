class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        vector<int>vec(len+1, -1);
        for(int i = 0; i<len; i++)
        {
            vec[nums[i]] = nums[i];
        }

        for(int i = 0; i<vec.size(); i++)
        {
            if(vec[i] == -1)
            {
             return i;
            }
        }
        return 0;
    }
};