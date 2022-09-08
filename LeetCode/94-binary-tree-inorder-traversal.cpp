///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursive
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        vector<int> l = inorderTraversal(root->left);
        res.insert(res.end(), l.begin(), l.end());
        
        res.push_back(root->val);
        
        vector<int> r = inorderTraversal(root->right);
        res.insert(res.end(), r.begin(), r.end());
        
        return res;
    }
};
