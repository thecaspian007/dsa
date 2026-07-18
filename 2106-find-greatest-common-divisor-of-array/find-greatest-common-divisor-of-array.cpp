class Solution {
public:
    int findLarge(vector<int>& nums){
        int lg = INT_MIN;
        for(int num : nums){
            lg = max(lg, num);
        }
        return lg;
    }

    int findSmall(vector<int>& nums){
        int sm = INT_MAX;
        for(int num : nums){
            sm = min(sm, num);
        }
        return sm;
    }
    int findGCD(vector<int>& nums) {
        int len = nums.size();
        if (len == 0){
            return -1;
        }
        int small = findSmall(nums);
        int large = findLarge(nums);
        return gcd(small, large);
    }
};