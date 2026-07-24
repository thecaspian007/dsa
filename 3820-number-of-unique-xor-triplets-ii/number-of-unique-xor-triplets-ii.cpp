class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       const int MAXX = 2048;
        vector<bool> dp(MAXX, false);
        dp[0] = true;
        for (int step = 0; step < 3; step++) {
            vector<bool> next(MAXX, false);
            for (int x = 0; x < MAXX; x++) {
                if (!dp[x]) continue;
                for (int val : nums) {
                    next[x ^ val] = true;
                }
            }
            dp = move(next);
        }
        int ans = 0;
        for (bool x : dp)
            ans += x;
        return ans; 
    }
};