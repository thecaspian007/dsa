class Solution {
public: 
    long long maxScore = 0;
    int count = 0;
    int n;

    int dfs(int node, vector<vector<int>>& children) {

        long long score = 1;
        int subtreeSize = 1;

        for (int child : children[node]) {
            int childSize = dfs(child, children);
            subtreeSize += childSize;
            score *= childSize;
        }

        int remaining = n - subtreeSize;

        if (remaining > 0)
            score *= remaining;

        if (score > maxScore) {
            maxScore = score;
            count = 1;
        } else if (score == maxScore) {
            count++;
        }

        return subtreeSize;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }
        dfs(0, children);
        return count;
    }
};