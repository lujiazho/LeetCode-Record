///////////////////////////////////////////////////////////////////////////////////////////////
// hard to solve this by self
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int res = 0;
    
    int minCameraCover(TreeNode* root) 
    {
        // if root return 0, we have to give it a camera
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) 
    {
        if (!root) return 1;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) // at least one child is not monitored
        {
            res++;
            return 2; // flag this node as having camera
        }
        // if as least one child having camera, return 1 means this node is monitored but not having camera; if no child has camera, return 0 means this node is not monitored
        return left == 2 || right == 2 ? 1 : 0;
    }
};