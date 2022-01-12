///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n), traversal over the whole tree
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    int value;
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        value = val;
        if (root != NULL)
            dfs(root);
        else
            root = new TreeNode(value);
        return root;
    }
    void dfs(TreeNode* node){
        if (value > node->val){
            if (node->right != NULL)
                dfs(node->right);
            else
                node->right = new TreeNode(value);
        }else{
            if (node->left != NULL)
                dfs(node->left);
            else
                node->left = new TreeNode(value);
        }
    }
};