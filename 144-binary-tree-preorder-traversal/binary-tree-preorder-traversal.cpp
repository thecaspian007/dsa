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
    // void preOrder(TreeNode* root, vector<int>&ans){
        
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        TreeNode* curr = root;
        while(curr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == nullptr){
                    pred->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};