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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        return res;
    }

    void dfsSerialize(TreeNode* node, string& res) {
        if (!node) {
            res += "N,";
            return;
        }

        res += to_string(node->val) + ",";
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        string temp;

        for (char c : data) {
            if (c == ',') {
                vals.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        int idx = 0;
        return dfsDeserialize(vals, idx);
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& idx) {
        if (vals[idx] == "N") {
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[idx++]));

        node->left = dfsDeserialize(vals, idx);
        node->right = dfsDeserialize(vals, idx);

        return node;
    }
};