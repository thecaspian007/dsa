class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        // Iterator pointing to the median
        auto mid = next(window.begin(), k / 2);
        vector<double> ans;
        for (int i = k;; i++) {
            // Calculate median
            if (k % 2 == 1) {
                ans.push_back((double)*mid);
            } else {
                ans.push_back(((double)*mid + *prev(mid)) / 2.0);
            }
            // Last window processed
            if (i == nums.size())
                break;
            // Insert new element
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;
            // Remove outgoing element
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }
        return ans;
    }
};