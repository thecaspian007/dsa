/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode * lh = lowestCommonAncestor(root->left, p, q);
        TreeNode * rh = lowestCommonAncestor(root->right, p, q);

        if(lh && rh){
            return root;
        }
        return lh ? lh : rh;
    }
};