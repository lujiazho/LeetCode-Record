///////////////////////////////////////////////////////////////////////////////////////////////
// not really hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    // return single side maximum path
    int dfs(TreeNode* root, int& maxSum){
        if(!root) return 0;
        // if less than 0, we set to zero to not consider
        int left = max(0, dfs(root->left, maxSum));
        int right = max(0, dfs(root->right, maxSum));
        // update res
        maxSum = max(maxSum, left + right + root->val);
        // return single maximum path sum
        return max(left, right) + root->val;
    }
};