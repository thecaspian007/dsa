class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
       int start = 0;
       int end = len-1;

        if(start>end)
        {
            return -1;
        }

        if(nums[0] == target)
        {
            return 0;
        }

        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[start]<=nums[mid])
            {
                if(nums[start]<= target && target <= nums[mid])
                {
                   end = mid-1;
                }
                else
                {
                   start = mid+1;
                }
            }
            else
            {
                 if(nums[mid]<= target && target <= nums[end])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};