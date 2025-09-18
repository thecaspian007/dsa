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
    void inorder(TreeNode* root, vector<int> &inOrdered){
        if(root == nullptr){
            return;
        }
        inorder(root->left, inOrdered);
        inOrdered.push_back(root->val);
        inorder(root->right, inOrdered);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inOrdered;
        if(root == nullptr){
            return inOrdered;
        }
        inorder(root, inOrdered);
        return inOrdered;
    }
};