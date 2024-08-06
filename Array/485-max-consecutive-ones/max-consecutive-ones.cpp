class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        int maxi = 0;

        if(len == 0)
        {
            return ans;
        }

        for(int i = 0; i<len; i++){
            if(nums[i] == 1)
            {
                ans++;
                maxi = max(maxi, ans);
            }
            else
            {
                ans = 0;
            }
        }
    return maxi;
    }
};