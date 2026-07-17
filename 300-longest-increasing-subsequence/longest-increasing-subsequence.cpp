class Solution {
public:
    int binarySearch(vector<int>& tails, int target) {
        int low = 0;
        int high = tails.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tails[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            int idx = binarySearch(tails, num);
            if (idx == tails.size())
                tails.push_back(num);
            else
                tails[idx] = num;
        }
        return tails.size();
    }
};