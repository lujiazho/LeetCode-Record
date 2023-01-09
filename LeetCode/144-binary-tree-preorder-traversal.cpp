///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        vector<int> res = {root->val};
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};