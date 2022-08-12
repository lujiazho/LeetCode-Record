///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursion
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        int v = root->val;
        int vp = p->val, vq = q->val;
        if (v <= vp && v >= vq || v <= vq && v >= vp) return root;
        if (v < vp && v < vq) return lowestCommonAncestor(root->right, p, q);
        if (v > vp && v > vq) return lowestCommonAncestor(root->left, p, q);
        return NULL;
    }
};