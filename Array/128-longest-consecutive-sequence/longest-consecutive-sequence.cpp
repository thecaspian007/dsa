class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        unordered_set<int> s;
       for(int i=0;i<n;i++)
           s.insert(nums[i]);
       int ans=1;
       for(auto x:s)
       {
           if(s.find(x-1)!=s.end()) continue;
           else
           {
               int j=1,k=1;
               while(s.find(x+j)!=s.end())
               {
                   k++;
                   j++;
               }
               ans=max(ans,k);
           }
       }return ans;
    }
};