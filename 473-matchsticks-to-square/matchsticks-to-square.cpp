class Solution {
public:
    vector<int> nums;
    vector<int> dp;
    int target;
    bool dfs(int mask,int curr)
    {
        if(mask==(1<<nums.size())-1)
            return curr==0;
        if(dp[mask]!=-1)
            return dp[mask];
        for(int i=0;i<nums.size();i++)
        {
            if(mask&(1<<i))
                continue;
            if(curr+nums[i]>target)
                continue;
            if(dfs(mask|(1<<i), (curr+nums[i])%target))
                return dp[mask]=1;
        }
        return dp[mask]=0;
    }

    bool makesquare(vector<int>& matchsticks) {
        nums=matchsticks;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4)
            return false;
        target=sum/4;
        sort(nums.rbegin(),nums.rend());
        dp.assign(1<<nums.size(),-1);
        return dfs(0,0);
    }
};