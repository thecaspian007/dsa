class Solution {
public:
    bool subsetSum(vector<int>& nums, int val, int n)
    {
        vector<vector<bool>> t(n+1, vector<bool>(val+1, false));
        for(int i = 0; i< n+1; i++)
        {
            t[i][0] = true;
        }

         for(int i = 1; i< n+1; i++)
        {
            for(int j = 1; j< val+1; j++)
            {
                if(nums[i-1] <= j)
                {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else
                {
                     t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][val];
    }
   
    bool canPartition(vector<int>& nums) {
       int len = nums.size();
       int sum = 0;
       if(len == 0)
       {
        return false;
       }

       for(int i = 0; i<len; i++)
       {
        sum += nums[i];
       }
       
       if(sum%2 != 0)
       {
        return false;
       }
       else
       {
        return subsetSum(nums, sum/2, len);
       }
    }
};