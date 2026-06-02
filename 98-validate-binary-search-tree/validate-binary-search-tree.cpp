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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        bool ans = true;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while(curr){
            if(curr->left == nullptr){
             if(prev && prev->val >= curr->val){
                ans = false;
             }
            prev = curr;
            curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = nullptr;
                    if(prev && prev->val >= curr->val){
                        ans = false;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};