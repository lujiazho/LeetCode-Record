///////////////////////////////////////////////////////////////////////////////////////////////
// good solution from others
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long totalTreeSum=0, res=0;
    const int MOD = 1e9+7;
    int SumUnder(TreeNode* root) {
        if(!root) return 0;
        long long sum = SumUnder(root->left) + SumUnder(root->right) + root->val;
        // cur the edge above this node
        res = max(res, sum*(totalTreeSum-sum));
        return sum;
    }
    int maxProduct(TreeNode* root, long long acc=0) {
        // get total sum, the res will not be calculated correctly here
        totalTreeSum=SumUnder(root);
        // get result when traverse
        SumUnder(root);
        return res % MOD;
    }
};