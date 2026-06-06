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
    vector<vector<int>> ans;
    bool isLeaf(TreeNode* root){
        return root && !root->left && !root->right;
    }

    void hasPath(TreeNode* root, int targetSum, vector<int> &path){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        if (isLeaf(root)) {
            if(targetSum == root->val) {
                ans.push_back(path);
            }
        }
        hasPath(root->left, targetSum - root->val, path);
        hasPath(root->right, targetSum - root->val, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        if(root == nullptr){
            return ans;
        } 
        hasPath(root, targetSum, path);
        return ans;
    }
};