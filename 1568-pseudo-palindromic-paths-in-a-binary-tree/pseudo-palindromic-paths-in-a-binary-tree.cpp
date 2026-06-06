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
        return root && !root->left && !root->right;
    }
    int hasPath(TreeNode* root, int mask){
        if(root == nullptr){
            return 0;
        }
        mask ^= (1 << root->val);
        if(isLeaf(root)){
            return (mask & (mask - 1)) == 0;
        }
        return hasPath(root->left, mask) + hasPath(root->right, mask);

    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        if(root == nullptr){
            return 0;
        }
        return hasPath(root, 0);
    }
};