class Solution {
public:
    int maxEle(vector<int>& nums){
        int maxVal = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            maxVal = max(maxVal, nums[i]);
        }

        return maxVal;
    }

    long long calOperations(vector<int>& nums, int penalty){
        long long operations = 0;

        for(int i = 0; i < nums.size(); i++){
            operations += (nums[i] - 1) / penalty;
        }

        return operations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = maxEle(nums);

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long operations = calOperations(nums, mid);
            if(operations <= maxOperations){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};