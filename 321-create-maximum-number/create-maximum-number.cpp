class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;
        for (int x : nums) {
            while (!st.empty() && drop > 0 && st.back() < x) {
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }
        st.resize(k);
        return st;
    }

    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size()) return true;
        if (i == a.size()) return false;
        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        for (int x = max(0, k - n); x <= min(k, m); x++) {
            vector<int> a = maxSubsequence(nums1, x);
            vector<int> b = maxSubsequence(nums2, k - x);
            vector<int> cur = merge(a, b);
            if (greater(cur, 0, ans, 0))
                ans = cur;
        }
        return ans;
    }
};