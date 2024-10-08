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
    void inOrder(TreeNode* root, vector<int> &v1)
    {
        if(root == NULL)
        {
            return;
        }
        inOrder(root->left, v1);
        v1.push_back(root->val);
        inOrder(root->right, v1);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> v1;
        inOrder(root, v1);
       for(int i=1;i<v1.size();i++){
            if(v1[i]<=v1[i-1]){
                return false;
            }
        }
        return true;
    }
};