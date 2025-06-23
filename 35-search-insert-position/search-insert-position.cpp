class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();

        if(len == 0)
        {
            return -1;
        }
        int start = 0;
        int end = len-1;

        while(start <= end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return start;
    }
};