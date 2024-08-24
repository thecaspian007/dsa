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
    int countNodeVal(TreeNode* root, int &num)
    {
         if(root == nullptr)
        {
            return 0;
        }
        num++;
        countNodeVal(root->left, num);
        countNodeVal(root->right, num);
        return num;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }

        int num = 0;
        countNodeVal(root, num);
        return num;
    }
};