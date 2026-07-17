class Solution {
public:
    bool canReach(vector<int>& dist, double hour, int speed) {
        double totalTime = 0.0;
        int n = dist.size();
        for (int i = 0; i < n - 1; i++) {
            totalTime += ceil((double)dist[i] / speed);
        }
        totalTime += (double)dist[n - 1] / speed;
        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1)
            return -1;
        int low = 1;
        int high = 10000000;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReach(dist, hour, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};