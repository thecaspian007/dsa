class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int mask, int remaining, int n)
    {
        if(dp.count(mask))
            return dp[mask];
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
                continue;
            if(i + 1 >= remaining)
                return dp[mask] = true;
            if(!solve(mask | (1 << i), remaining - (i + 1), n))
                return dp[mask] = true;
        }
        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
       if(desiredTotal <= 0)
            return true;
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(sum < desiredTotal)
            return false;
        return solve(0, desiredTotal, maxChoosableInteger); 
    }
};