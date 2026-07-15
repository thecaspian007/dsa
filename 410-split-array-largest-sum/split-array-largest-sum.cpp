class Solution {
public:
    int maxEle(vector<int>& nums){
        int maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }

    int sumEle(vector<int>& nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int calSubarrays(vector<int>& nums, int largestSum){
        int subarrays = 1;
        int currSum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(currSum + nums[i] <= largestSum){
                currSum += nums[i];
            }
            else{
                subarrays++;
                currSum = nums[i];
            }
        }
        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = maxEle(nums);
        int high = sumEle(nums);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int requiredSubarrays = calSubarrays(nums, mid);
            if(requiredSubarrays <= k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};