class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans;
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        if(len == 0)
        {
            return;
        }

        for(int i = 0; i<len; i++)
        {
            if(nums[i] == 0)
            {
                count1++;
            }
            else if(nums[i] == 1)
            {
                count2++;
            } 
            else
            {
                count3++;
            }
        }
        int i = 0;
        while(count1--)
        {
            nums[i] = 0;
            i++;
        }
        while(count2--)
        {
            nums[i] = 1;
            i++;
        }
        while(count3--)
        {
             nums[i] = 2;
             i++;
        }
    }
};