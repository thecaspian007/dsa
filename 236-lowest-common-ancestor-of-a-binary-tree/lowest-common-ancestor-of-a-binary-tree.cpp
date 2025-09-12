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
        if(root == NULL)
        {
            return root;
        }

        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }

        TreeNode* lca = lowestCommonAncestor(root->left, p, q);
        TreeNode* rca = lowestCommonAncestor(root->right, p, q);

        if(lca != NULL && rca != NULL)
        {
            return root;
        }

        if(lca != NULL)
         {
            return lca;
         }
         else
         {
            return rca;
         }
    }
};