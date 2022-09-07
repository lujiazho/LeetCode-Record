///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursive
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string l="", r="";
        if (root->right){
            l = "(" + tree2str(root->left) + ")";
            r = "(" + tree2str(root->right) + ")";
        }else if (root->left){
            l = "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + l + r;
    }
};