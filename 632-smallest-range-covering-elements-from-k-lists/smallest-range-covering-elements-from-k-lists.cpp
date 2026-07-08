class Solution {
public:
    struct Node {
        int value;
        int row;   
        int col; 

        bool operator>(const Node &other) const {
            return value > other.value;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int currentMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }
        int start = 0;
        int end = INT_MAX;
        while (pq.size() == nums.size()) {
            Node curr = pq.top();
            pq.pop();
            int currentMin = curr.value;
            if (currentMax - currentMin < end - start ||
                (currentMax - currentMin == end - start &&
                 currentMin < start)) {
                start = currentMin;
                end = currentMax;
            }
            if (curr.col + 1 < nums[curr.row].size()) {
                int nextValue = nums[curr.row][curr.col + 1];
                pq.push({nextValue, curr.row, curr.col + 1});
                currentMax = max(currentMax, nextValue);
            }
            else {
                break;
            }
        }
        return {start, end};
    }
};