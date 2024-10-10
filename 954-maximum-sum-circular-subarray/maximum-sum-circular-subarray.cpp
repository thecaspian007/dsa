class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }

        int total = 0;
        int temp_max = 0;
        int temp_min = 0;
        int min_sum = INT_MAX;
        int max_sum = INT_MIN;

        for(int i = 0; i< len; i++)
        {
            total += nums[i];
           temp_max += nums[i];
            temp_min += nums[i];

            if(temp_max < nums[i])
            {
                temp_max = nums[i];
            }

            if(temp_min > nums[i])
            {
                temp_min = nums[i];
            }
            max_sum = max(max_sum, temp_max);
            min_sum = min(min_sum, temp_min);
        }

        if(total == min_sum) return max_sum;
        return max(max_sum, total-min_sum);
    }
};