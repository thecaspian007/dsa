class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> best(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            best[i] = nums[i];
            ans += nums[i];
        }
        for (int rot = 1; rot < n; rot++) {
            long long curr = 1LL * rot * x;
            for (int i = 0; i < n; i++) {
                best[i] = min(best[i], 1LL * nums[(i - rot + n) % n]);
                curr += best[i];
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};