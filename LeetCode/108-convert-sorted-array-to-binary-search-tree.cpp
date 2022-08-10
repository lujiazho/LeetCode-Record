///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursion
////////////////
// Time Complexity: O(n), if vector construction is not considered
// Space Complexity: O(nlogn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) return NULL;
        int l = 0, r = nums.size()-1;
        int ro = (l+r)>>1;
        TreeNode* root = new TreeNode(nums[ro]);
        
        vector<int> left = vector<int>(nums.begin(), nums.begin()+ro);
        root->left = sortedArrayToBST(left);
        
        vector<int> right = vector<int>(nums.begin()+ro+1, nums.end());
        root->right = sortedArrayToBST(right);
        
        return root;
    }
};