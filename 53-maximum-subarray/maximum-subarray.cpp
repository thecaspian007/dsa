class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        }

        int maxVal = INT_MIN;
        int currVal = 0;
        for(int i = 0; i< len; i++) {
            currVal += nums[i];
            maxVal = max(maxVal, currVal);
            if(currVal <0) {
                currVal = 0;
            }
        } 
        return maxVal;
    }
};