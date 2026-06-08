/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeDFS(TreeNode* root, string &ans)
    {
        if(root == nullptr)
        {
            ans += "#,";
            return;
        }
        ans += to_string(root->val) + ",";
        serializeDFS(root->left, ans);
        serializeDFS(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serializeDFS(root, ans);
        return ans;
    }

    TreeNode* build(vector<string>& nodes, int &idx)
    {
        if(nodes[idx] == "#")
        {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[idx++]));
        root->left = build(nodes, idx);
        root->right = build(nodes, idx);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;
        for(char ch : data)
        {
            if(ch == ',')
            {
                nodes.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += ch;
            }
        }
        int idx = 0;
        return build(nodes, idx);  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));