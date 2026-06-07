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
    bool isMirror(TreeNode* leftPt, TreeNode* rightPt){
        if(leftPt == nullptr && rightPt == nullptr){
            return true;
        }
        if(leftPt == nullptr || rightPt == nullptr){
            return false;
        }
        return leftPt->val == rightPt->val && isMirror(leftPt->left, rightPt->right) && isMirror(leftPt->right, rightPt->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isMirror(root->left, root->right);
    }
};