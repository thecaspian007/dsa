class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int eachCandy) {
        long long children = 0;
        for (int pile : candies) {
            children += pile / eachCandy;
            if (children >= k)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        for (int x : candies)
            total += x;
        if (total < k)
            return 0;
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAllocate(candies, k, mid)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};