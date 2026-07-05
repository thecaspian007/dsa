class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();

        vector<long long> preNum(n + 1, 0);
        vector<long long> preCost(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preNum[i + 1] = preNum[i] + nums[i];
            preCost[i + 1] = preCost[i] + cost[i];
        }

        const long long INF = 4e18;
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            long long extra = 1LL * k * (preCost[n] - preCost[i]);

            for (int j = i; j < n; j++) {
                long long cur =
                    preNum[j + 1] * (preCost[j + 1] - preCost[i]) +
                    extra +
                    dp[j + 1];

                dp[i] = min(dp[i], cur);
            }
        }
        return dp[0];
    }
};