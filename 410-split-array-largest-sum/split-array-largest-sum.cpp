class Solution {
public:
     bool canSplit(vector<int>& nums, int k, long long limit) {
        long long sum = 0;
        int parts = 1;
        for (int num : nums) {
            if (sum + num <= limit) {
                sum += num;
            } else {
                parts++;
                sum = num;
            }
        }
        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = 0;
        for (int x : nums)
            right += x;
        long long ans = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (int)ans;
    }
};