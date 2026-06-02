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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr){
            return -1;
        }
        int count =0, ans = -1;
        TreeNode* curr = root;
        while(curr){
            if(curr->left == nullptr){
                count++;
                if(count == k){
                    ans = curr->val;
                }
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
                    count++;
                    if(count == k){
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};