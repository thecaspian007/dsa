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
    map<int, map<int, multiset<int>>>mp;
    void dfs(TreeNode* node, int row, int col){
        if(node == nullptr){
            return;
        }
        mp[col][row].insert(node->val);
        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>>ans;

        for(auto &[col, rows] : mp){
            vector<int>curr;
            for(auto &[row, values] : rows){
                curr.insert(curr.end(), values.begin(), values.end());
            }
            ans.push_back(curr);
        }
        return ans;
    }
};