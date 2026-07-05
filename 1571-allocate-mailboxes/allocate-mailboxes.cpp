class Solution {
public:
    int n;
    vector<vector<int>> cost;
    vector<vector<int>> dp;
    int solve(int i,int k)
    {
        if(i==n)
            return 0;
        if(k==0)
            return 1e9;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=1e9;
        for(int j=i;j<n;j++)
        {
            ans=min(ans, cost[i][j]+solve(j+1,k-1));
        }
        return dp[i][k]=ans;
    }


    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        n=houses.size();
        cost.assign(n,vector<int>(n,0));
        for(int l=0;l<n;l++)
        {
            for(int r=l;r<n;r++)
            {
                int mid=(l+r)/2;
                for(int i=l;i<=r;i++)
                    cost[l][r]+=abs(houses[i]-houses[mid]);
            }
        }
        dp.assign(n,vector<int>(k+1,-1));
        return solve(0,k);
    }
};