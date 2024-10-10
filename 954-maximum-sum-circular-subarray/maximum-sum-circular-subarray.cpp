class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        
        int ans=INT_MIN;
        
        vector<int>l(n);
        vector<int>r(n);
        int s=nums[0];
        l[0]=nums[0];
        for(int i=1;i<n;i++)
        {
         s +=nums[i];
         l[i]=max(s,l[i-1]);
        }

        //for right
        s=nums[n-1];
        r[n-1]=s;
        for(int i=n-2;i>=0;i--)
        {
            s +=nums[i];
            r[i]=max(s,r[i+1]);
        }

        for(int i=0;i<n;i++)
        {
            int curr;
            curr =l[i];
            if(i!=n-1)
            {
             curr +=r[i+1];
            }
            ans=max(ans,curr);
        }


       int sum=0;
        for(int i=0;i<n;i++)
        {
        sum +=nums[i];
        ans=max(ans,sum);
        if(sum<0)
        {
            sum=0;
        }
        }


        return ans;

    }
};