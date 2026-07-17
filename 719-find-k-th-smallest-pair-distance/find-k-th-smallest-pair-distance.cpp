class Solution {
public:
    int countPairs(vector<int>& nums, int maxDistance) {
        int left = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > maxDistance)
                left++;
            count += (right - left);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums.front();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};