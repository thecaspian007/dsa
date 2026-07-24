class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums2[i], i});
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int value = arr[i].first;
            int index = arr[i].second;
            if (nums1[right] > value) {
                ans[index] = nums1[right];
                right--;
            } else {
                ans[index] = nums1[left];
                left++;
            }
        }
        return ans;
    }
};