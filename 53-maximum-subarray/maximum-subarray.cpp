class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int len = nums.size();
       if(len == 0)
       {
        return 0;
       }

       int max_so_far = INT_MIN;;
       int current_val = 0;
       int initial_val = 0;

       for(int i = 0; i<len; i++)
       {
        current_val += nums[i];
        max_so_far = max(max_so_far, current_val);
        if (current_val <0)
        {
            current_val=0;
        }
       }
       return max_so_far;
    }
};