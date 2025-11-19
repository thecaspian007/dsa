class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, bool> mp;
        for(int x : nums) {
            mp[x] = true;
        }
        while (mp[original]) {
            original *= 2;
        }
        return original;
    }
};