class Solution {
public:
    bool canRob(vector<int>& nums, int k, int capability)
    {
        int count = 0;
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] <= capability)
            {
                count++;
                i += 2;          // Cannot rob adjacent house
            }
            else
            {
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0; i< nums.size(); i++){
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }
        // int low = *min_element(nums.begin(), nums.end());
        // int high = *max_element(nums.begin(), nums.end());
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (canRob(nums, k, mid))
            {
                high = mid;      // Try smaller capability
            }
            else
            {
                low = mid + 1;   // Need larger capability
            }
        }

        return low;
    }
};