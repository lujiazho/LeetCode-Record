///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root){
            if (root->val == val) return root;
            if (root->val > val) root = root->left;
            else root = root->right;
        }
        return NULL;
    }
};