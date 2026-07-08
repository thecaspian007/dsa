class Solution {
public:
    struct Node {
        int value;
        int row;
        int col;
        bool operator>(const Node& other) const {
            return value > other.value;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }
        while (--k) {
            Node cur = pq.top();
            pq.pop();
            if (cur.col + 1 < n) {
                pq.push({
                    matrix[cur.row][cur.col + 1],
                    cur.row,
                    cur.col + 1
                });
            }
        }
        return pq.top().value;
    }
};