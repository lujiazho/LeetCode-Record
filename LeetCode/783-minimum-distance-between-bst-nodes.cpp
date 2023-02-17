///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int res = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
    // return min and max in this subtree
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return pair<int,int>(INT_MAX, INT_MIN);

        pair<int,int> lp = dfs(root->left);
        pair<int,int> rp = dfs(root->right);

        if (lp.second != INT_MIN) res = min(res, root->val-lp.second);
        if (rp.first != INT_MAX) res = min(res, rp.first-root->val);

        return pair<int,int>(min(lp.first, root->val), max(rp.second, root->val));
    }
};