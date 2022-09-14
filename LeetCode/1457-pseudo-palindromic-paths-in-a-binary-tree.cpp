///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, we only need to know the count of each value in this path
// to make it a palindrome, at most one value could have odd count
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    unordered_map<int, int> m; // val:num
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* node){
        if (!node) return;
        m[node->val] += 1;
        dfs(node->left);
        dfs(node->right);
        if (!node->left && !node->right) {
            int flag = 0;
            for (auto i:m){
                if (i.second % 2) flag += 1;
            }
            if (flag <= 1) res += 1;
        }
        m[node->val] -= 1;
    }
};