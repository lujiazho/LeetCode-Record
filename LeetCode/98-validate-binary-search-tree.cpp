///////////////////////////////////////////////////////////////////////////////////////////////
// not hard recursion
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    // min, max limit the range of the tree rooted at node
    bool isValidBST(TreeNode* node, TreeNode* minNode, TreeNode* maxNode){
        if (!node) return true;
        if (minNode && minNode->val >= node->val || maxNode && maxNode->val <= node->val)
            return false;
        return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
    }
};