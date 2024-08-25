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
    void inOrder(TreeNode* root, vector<int>&value)
    {
        if(root == nullptr)
        {
            return;
        }

        inOrder(root->left, value);
        value.push_back(root->val);
        inOrder(root->right, value);

        
    }
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        vector<int>val;
        inOrder(root, val);

        sort(val.begin(), val.end());

        int ans = val[1] - val[0];

        for(int i = 2; i< val.size(); i++)
        {
           ans = min(ans, abs(val[i] - val[i-1]));
        }
        return ans;
        
    }
};