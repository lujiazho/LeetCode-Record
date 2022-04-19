///////////////////////////////////////////////////////////////////////////////////////////////
// not really easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode *first, *second, *pre;
    void recoverTree(TreeNode* root) {
        first = NULL;
        second = NULL;
        pre = new TreeNode(INT_MIN);
        inorder(root);
        int val = first->val;
        first->val = second->val;
        second->val = val;
    }
    
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        
        if (!first && pre->val > root->val)
            first = pre;
        if (first && pre->val > root->val) // here cannot be else if because continuous swap would be ingored
            second = root;
        pre = root;
        
        inorder(root->right);
    }
};