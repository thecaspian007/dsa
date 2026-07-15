class Solution {
public:
    int maxEle(vector<int>& nums){
        int maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }

    int calTotal(vector<int>& nums, int divisor){
        int total = 0;

        for(int i = 0; i < nums.size(); i++){
            total += (nums[i] + divisor - 1) / divisor;
        }

        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = maxEle(nums);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int total = calTotal(nums, mid);
            if(total <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};