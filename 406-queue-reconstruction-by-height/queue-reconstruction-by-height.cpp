class Solution {
public:
     static bool cmp(vector<int>& a, vector<int>& b) {
        // Taller people first
        if (a[0] != b[0])
            return a[0] > b[0];
        // Same height -> smaller k first
        return a[1] < b[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for (auto &person : people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};