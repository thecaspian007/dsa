class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        stack<int>s;
        int mx = INT_MIN;

        for(int i = 0; i< nums.size(); ++i)
        {
            if(s.empty() || nums[s.top()] > nums[i])
            {
                s.push(i);
            }
        }

        for(int j = nums.size()-1; j>= 0; --j)
        {
             while(!s.empty() && nums[s.top()] <= nums[j])
            {
                mx = max(mx, j- s.top());
                s.pop();
            }
        }

        
        return mx;
    }
};