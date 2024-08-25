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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root == nullptr)
        {
            return ans;
        }

        queue<TreeNode*>q;
        double sum = 0;
        int count = 0;

        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL)
            {
                double avg = sum/count;
                ans.push_back(avg);
                count = 0;
                sum = 0;
                if(q.size()>0)
                {
                    q.push(NULL);
                }
            }
            else
            {
                sum += front->val;
                count++;
                if(front ->right)
                {
                    q.push(front->right);
                }

                 if(front ->left)
                {
                    q.push(front->left);
                }
            }
        }
        return ans;

    }
};