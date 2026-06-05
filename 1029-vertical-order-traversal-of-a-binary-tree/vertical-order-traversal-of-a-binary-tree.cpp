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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> Q;
        Q.push({root, {0, 0}});
        while(!Q.empty()) {
            auto it = Q.front();
            Q.pop();
            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;
            mp[col][row].insert(node->val);
            if(node->left) Q.push({node->left, {row + 1, col - 1}});
            if(node->right) Q.push({node->right, {row + 1, col + 1}});
        }
        vector<vector<int>> ans;
        for(auto col : mp) {
            vector<int> temp;
            for(auto row : col.second) {
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};