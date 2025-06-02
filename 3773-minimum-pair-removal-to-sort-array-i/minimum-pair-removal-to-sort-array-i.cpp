class Solution {
public:
    bool isSorted(const vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        while (!isSorted(nums) && nums.size() > 1) {
            int minSum = 1e9;
            int pos = -1;
            
            for (int i = 0; i < nums.size() - 1; i++) {
                int curSum = nums[i] + nums[i + 1];
                if (curSum < minSum) {
                    minSum = curSum;
                    pos = i;
                }
            }
            nums[pos] = nums[pos] + nums[pos + 1];
            
            nums.erase(nums.begin() + pos + 1);
            operations++;
        }
        
        return operations;
    }
};