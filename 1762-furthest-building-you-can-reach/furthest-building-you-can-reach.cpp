class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            // No resources needed
            if (climb <= 0)
                continue;
            // Assume ladder is used
            pq.push(climb);
            // Too many ladder usages
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            // Not enough bricks
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};