class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        map<long long, long long> dp;
        dp[0] = 0; 
        for (auto& ride : rides) {
            long long start = ride[0];
            long long end = ride[1];
            long long tip = ride[2];
            long long profit = end - start + tip;
            auto it = dp.upper_bound(start);
            it--; 
            long long bestBefore = it->second;
            long long total = bestBefore + profit;
            if (total > dp.rbegin()->second) {
                dp[end] = total;
            }
        }
        return dp.rbegin()->second;
    }
};