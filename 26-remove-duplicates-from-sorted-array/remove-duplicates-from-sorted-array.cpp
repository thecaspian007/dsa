class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        if(len == 0)
        {
            return count;
        }
        int index = 0;
    
        for(int i = 0; i< len; i++)
        {
            if(i == 0)
            {
                nums[index] = nums[0];
                count++;
            }
            else if(i != len-1 && nums[index] != nums[i])
            {
                index++;
                nums[index] = nums[i];
                count++;
            }
            else if(i == len-1 && nums[i] != nums[i-1])
            {
                index++;
                nums[index] = nums[i];
                count++;
            }

        }
        return count;
    }
};