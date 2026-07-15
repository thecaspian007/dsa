class Solution {
public:
     bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentWeight = 0;
        for (int weight : weights) {
            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            } else {
                daysNeeded++;
                currentWeight = weight;
            }
        }
        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};