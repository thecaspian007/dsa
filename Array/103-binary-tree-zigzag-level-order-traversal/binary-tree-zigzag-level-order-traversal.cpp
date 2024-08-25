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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> res;
        if (root == nullptr) return res; 
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int s = q.size();
            vector<int> v; 

            for (int i = 0; i < s; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (leftToRight) {
                    v.push_back(temp->val);
                } else {
                    v.insert(v.begin(), temp->val); 
                }
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(v); 
            leftToRight = !leftToRight; 
        }
        return res;
    }
};