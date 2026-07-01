class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        int Max = n + 1;
        vector<int> dp(n + 1, Max);
        dp[0] = 0;
        for (int amount = 1; amount <= n; amount++) {
            for (int square : squares) {
                if (square <= amount) {
                    dp[amount] = min(dp[amount], dp[amount - square] + 1);
                }
            }
        }
        return dp[n]; 
    }
};