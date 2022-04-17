///////////////////////////////////////////////////////////////////////////////////////////////
// easy, I already find the pattern behind this kind of recursive problem
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* left = increasingBST(root->left);
        TreeNode* right = increasingBST(root->right);
        root->left = NULL;
        if (left){
            TreeNode* node = left;
            while (node->right)
                node = node->right;
            node->right = root;
        }
        root->right = right;
        return left?left:root;
    }
};