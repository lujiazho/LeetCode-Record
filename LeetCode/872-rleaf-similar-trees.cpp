///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> A, B;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, A);
        dfs(root2, B);
        return A == B;
    }
    void dfs(TreeNode* node, vector<int>& leaves) {
        if (!node) return;
        if (!node->left && !node->right)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};