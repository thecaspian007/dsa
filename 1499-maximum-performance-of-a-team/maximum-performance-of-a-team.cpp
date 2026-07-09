class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9 + 7;
        // {efficiency, speed}
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        // Sort by efficiency in descending order
        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long speedSum = 0;
        long long answer = 0;
        for (auto &engineer : engineers) {
            int currEfficiency = engineer.first;
            int currSpeed = engineer.second;
            speedSum += currSpeed;
            pq.push(currSpeed);
            // Keep only k engineers
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            answer = max(answer, speedSum * currEfficiency);
        }
        return answer % MOD;
    }
};