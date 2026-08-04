class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int num = mn; num <= mx; num++) {
            if (st.find(num) == st.end()) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};