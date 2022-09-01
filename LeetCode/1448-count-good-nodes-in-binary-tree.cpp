///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int res = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }
    void dfs(TreeNode* node, int MAX){
        if (!node) return;
        if (node->val >= MAX) {
            res += 1;
        }
        dfs(node->left, max(MAX, node->val));
        dfs(node->right, max(MAX, node->val));
    }
};