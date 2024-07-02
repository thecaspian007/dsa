class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();

        if(len == 0)
        {
            return 0;
        }
        int maxi = nums[0];
        int sum = 0;

        for(int i = 0; i<len; i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);

            if(sum <0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};