class Solution {
public:
    int dfs(TreeNode* root, int maxVal) {
        if (!root) return 0;

        int count = 0;

        if (root->val >= maxVal) {
            count = 1;
            maxVal = root->val;
        }

        count += dfs(root->left, maxVal);
        count += dfs(root->right, maxVal);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};