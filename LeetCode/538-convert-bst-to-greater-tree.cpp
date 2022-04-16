///////////////////////////////////////////////////////////////////////////////////////////////
// not really hard, but today my head is a little bit cluttered
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
    int dfs(TreeNode* root, int upper_right){
        if (!root) return 0;
        int val = root->val;
        int right = dfs(root->right, upper_right);
        root->val += right + upper_right;
        return dfs(root->left, root->val) + val + right;
    }
};