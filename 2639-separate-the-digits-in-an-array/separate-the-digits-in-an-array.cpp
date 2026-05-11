class Solution {
public:
    void subDivide(int val, vector<int>&ans) {
        if(val/10 == 0) {
            ans.push_back(val);
            return;
        }
        subDivide(val/10, ans);
        ans.push_back(val%10);
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        if(nums.size() == 0){
            return ans;
        }
        for(int num: nums){
            subDivide(num, ans);
        }
        return ans;
    }
};