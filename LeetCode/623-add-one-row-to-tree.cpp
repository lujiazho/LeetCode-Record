///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursion, first time to add default value to given func in leetcode
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth, int left=1) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            if (left == 1) newRoot->left = root;
            else if(left == 0) newRoot->right = root;
            return newRoot;
        }
        if (root->left || (!root->left && depth==2)) root->left = addOneRow(root->left, val, depth-1, 1);
        if (root->right || (!root->right && depth==2)) root->right = addOneRow(root->right, val, depth-1, 0);
        return root;
    }
};