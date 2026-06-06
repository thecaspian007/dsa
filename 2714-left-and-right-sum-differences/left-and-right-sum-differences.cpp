class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       vector<int>ans;
       int len = nums.size();
       if(len ==0){
        return ans;
       } 
       vector<int>left;
       vector<int>right;
       int leftSum = 0, rightSum=0;
       for(int i = 0; i<len; i++){
        left.push_back(leftSum);
        right.push_back(rightSum);
        leftSum = leftSum + nums[i];
        rightSum = rightSum + nums[len-1-i];
       }
       reverse(right.begin(), right.end());
       for(int i = 0; i<len; i++){
        int diff = abs(right[i] - left[i]);
        ans.push_back(diff);
       }
       return ans;
    }
};