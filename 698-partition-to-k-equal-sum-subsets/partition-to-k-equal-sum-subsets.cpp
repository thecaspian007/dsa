class Solution {
public:
    vector<int> numbers;
    vector<int> dp;
    int target;
    bool dfs(int mask,int curr)
    {
        if(mask==(1<<numbers.size())-1)
            return curr==0;
        if(dp[mask]!=-1)
            return dp[mask];
        for(int i=0;i<numbers.size();i++)
        {
            if(mask&(1<<i))
                continue;
            if(curr+numbers[i]>target)
                continue;
            if(dfs(mask|(1<<i), (curr+numbers[i])%target))
                return dp[mask]=1;
        }
        return dp[mask]=0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        numbers=nums;
        int sum=accumulate(numbers.begin(),numbers.end(),0);
        if(sum%k)
            return false;
        target=sum/k;
        dp.assign(1<<numbers.size(),-1);
        sort(numbers.rbegin(),numbers.rend());
        return dfs(0,0);
    }
};