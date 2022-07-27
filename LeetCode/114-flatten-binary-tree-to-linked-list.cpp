///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* most_right = root->left;
        if (most_right) {
            while (most_right && most_right->right) most_right = most_right->right;
            most_right->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};