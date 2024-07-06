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
     void helper(TreeNode* root) {
        if(root==nullptr) return;
         
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        TreeNode* dummy = root;
        while(dummy->right){
            dummy = dummy->right;
        }
        dummy->right = tmp;

        
        helper(root->right);
        
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};