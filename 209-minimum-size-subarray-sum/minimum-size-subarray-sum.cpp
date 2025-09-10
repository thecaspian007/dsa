class Solution {
public:
    bool checkExist(int mid, int x, int n, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        for (j = 0; j < mid; j++) {
            sum += nums[j];
        }
        while (j < n) {
            if (sum >= x) return true;

            sum += nums[j];
            sum -= nums[i];
            j++;
            i++;
        }
        return sum >= x;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 1, h = n; 
        int ans = INT_MAX;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (checkExist(mid, target, n, nums)) {
                ans = mid;
                h = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};