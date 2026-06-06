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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }

    void path(TreeNode* root, vector<string>&ans, string val){
        if(isLeaf(root)){
           ans.push_back(val);
           return; 
        }
        if(root->left){
            path(root->left, ans, val + "->" + to_string(root->left->val));
        }
        if(root->right) {
            path(root->right, ans, val + "->" + to_string(root->right->val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>ans;
      if(root == nullptr){
        return ans;
      }
      path(root, ans, to_string(root->val));
      return ans;
    }
};