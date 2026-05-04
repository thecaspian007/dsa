class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int len = nums.size();
      if(len == 0){
        return;
      }  
      int nextNonZero = 0;
      for(int i = 0; i<len; i++){
        if(nums[i] != 0){
            swap(nums[nextNonZero], nums[i]);
            nextNonZero++;
        }
      }
    }
};