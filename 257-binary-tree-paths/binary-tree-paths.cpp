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
    void path(vector<string>&ans, TreeNode* root, string val){
        if(!root->left && !root->right) {
            ans.push_back(val);
            return;
        }
        if(root->left){
            path(ans, root->left, val + "->" + to_string(root->left->val));
        }
        if(root->right){
            path(ans, root->right, val + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root){
            return ans;
        }
        path(ans, root, to_string(root->val));
        return ans;
    }
};