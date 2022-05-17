///////////////////////////////////////////////////////////////////////////////////////////////
// easy dfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int val;
    TreeNode* res;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        val = target->val;
        dfs(cloned);
        return res;
    }
    void dfs(TreeNode* node){
        if (!node) return;
        if (node->val == val){
            res = node;
            return;
        }
        dfs(node->left);
        dfs(node->right);
    }
};