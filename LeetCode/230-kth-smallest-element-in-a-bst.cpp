///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int res = -1;
    int kk = -1;
    int kthSmallest(TreeNode* root, int k) {
        kk = k;
        dfs(root, 0);
        return res;
    }
    int dfs(TreeNode* root, int upper_less_num){
        if (!root) return 0;
        int left = dfs(root->left, upper_less_num);
        int right = dfs(root->right, left+upper_less_num+1);
        if (upper_less_num + left == kk-1) res = root->val;
        return left + 1 + right;
    }
};