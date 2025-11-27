class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix(k, 1e15);
        prefix[k - 1] = 0;
        long long res = -1e15, pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            res = max(res, pre - prefix[i % k]);
            prefix[i % k] = min(prefix[i % k], pre);
        }
        return res;
    }
};