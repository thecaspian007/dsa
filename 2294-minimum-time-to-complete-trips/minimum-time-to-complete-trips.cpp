class Solution {
public:
     bool canCompleteTrips(vector<int>& time, long long totalTrips, long long givenTime) {
        long long trips = 0;
        for (int t : time) {
            trips += givenTime / t;
            if (trips >= totalTrips)
                return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canCompleteTrips(time, totalTrips, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};