///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return res;
    }
    void dfs(TreeNode* node, int acc, int targetSum) {
        if (!node) return;
        
        acc += node->val;
        cur.push_back(node->val);
        
        if (!node->left && !node->right) {
            if (acc == targetSum) res.push_back(cur);
        } else {
            dfs(node->left, acc, targetSum);
            dfs(node->right, acc, targetSum);
        }
        cur.pop_back();
    }
};