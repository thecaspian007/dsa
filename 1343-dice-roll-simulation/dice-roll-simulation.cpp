class Solution {
public:
    const int MOD = 1e9+7;

    int dp[5001][7][16];

    vector<int> limit;

    int N;

    int solve(int pos,int last,int cnt)
    {
        if(pos==N)
            return 1;
        if(dp[pos][last][cnt]!=-1)
            return dp[pos][last][cnt];
        long long ans=0;
        for(int dice=1;dice<=6;dice++)
        {
            if(dice==last)
            {
                if(cnt<limit[dice-1])
                {
                    ans+=solve(pos+1,dice,cnt+1);
                }
            }
            else
            {
                ans+=solve(pos+1,dice,1);
            }
            ans%=MOD;
        }
        return dp[pos][last][cnt]=ans;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        limit=rollMax;
        N=n;
        return solve(0,0,0);
    }
};