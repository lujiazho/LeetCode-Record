///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
#define ll long long
class Solution {
public:
    ll ans = 0;
    void dfs(TreeNode *root, ll tmp){
        if(root->left== NULL && root->right==NULL){
            tmp = tmp*10 + root->val;
            ans += tmp;
            return;
        }
        tmp = tmp*10 + root->val;
        if(root->left) dfs(root->left, tmp);
        if(root->right) dfs(root->right, tmp);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return int(ans);
    }
};