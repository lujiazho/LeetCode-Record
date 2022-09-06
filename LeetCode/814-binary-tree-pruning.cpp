///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursive
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* left = pruneTree(root->left);
        TreeNode* right = pruneTree(root->right);

        if (!left && !right && root->val==0)
            return NULL;
        root->left = left;
        root->right = right;
        return root;
    }
};