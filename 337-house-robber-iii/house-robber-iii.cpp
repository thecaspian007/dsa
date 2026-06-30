/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;

    int solve(TreeNode* node, bool canRob)
    {
        if (node == nullptr)
            return 0;

        if (dp[node].size() && dp[node][canRob] != -1)
            return dp[node][canRob];

        if (dp[node].empty()){
            dp[node] = vector<int>(2, -1);
        }
        if (!canRob)
        {
            return dp[node][0] = solve(node->left, true) + solve(node->right, true);
        }

        int rob = node->val + solve(node->left, false) + solve(node->right, false);

        int skip = solve(node->left, true) + solve(node->right, true);
        return dp[node][1] = max(rob, skip);
    }
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};