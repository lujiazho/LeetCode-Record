///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursion
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // for empty tree case
        if (!root) return false;
        // for leaf check
        if (!root->left && !root->right && root->val == targetSum) return true;
        
        // recursive
        int val = targetSum - root->val;
        return hasPathSum(root->left, val) || hasPathSum(root->right, val);
    }
};