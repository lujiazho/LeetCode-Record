///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root || low > high) return 0;
    
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);
        
        return ((root->val<=high&&root->val>=low)?root->val:0) + left + right;
    }
};