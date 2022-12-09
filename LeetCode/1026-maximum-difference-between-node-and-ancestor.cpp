///////////////////////////////////////////////////////////////////////////////////////////////
// record the largest and smallest value from ancestors
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int ma=INT_MIN, int mi=INT_MAX) {
        if (!root) return ma - mi;
        ma = max(ma, root->val);
        mi = min(mi, root->val);
        return max(maxAncestorDiff(root->left, ma, mi), maxAncestorDiff(root->right, ma, mi));
    }
};