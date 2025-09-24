class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return false;
        }
        unordered_map<int, int>mp;
        for(int i = 0; i< len; i++){
            mp[nums[i]]++;
        }
        for(auto &it: mp){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
};