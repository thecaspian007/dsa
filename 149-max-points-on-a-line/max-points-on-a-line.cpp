class Solution {
public:
    double findSlope(vector<int> &p1, vector<int> &p2)
    {
        if (p1[0] == p2[0]) {
        return std::numeric_limits<double>::infinity();  // Vertical line slope
    }
    return static_cast<double>(p2[1] - p1[1]) / (p2[0] - p1[0]);
       
    }
    int maxPoints(vector<vector<int>>& points) {
       if (points.size() < 2) {
        return points.size();
    }

    int maxPointsOnLine = 0;

    for (int i = 0; i < points.size(); ++i) {
        map<double, int> slopeCount;
        int duplicates = 1;

        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i] == points[j]) {
                ++duplicates;
            } else {
                double slope = findSlope(points[i], points[j]);
                slopeCount[slope]++;
            }
        }

        int currentMax = 0;
        for (auto& count : slopeCount) {
            currentMax = max(currentMax, count.second);
        }

        maxPointsOnLine = max(maxPointsOnLine, currentMax + duplicates);
    }

    return maxPointsOnLine;
    }
};