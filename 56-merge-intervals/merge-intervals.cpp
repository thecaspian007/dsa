class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // Last merged interval
            vector<int>& last = ans.back();
            // Overlap
            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            }
            // No overlap
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};