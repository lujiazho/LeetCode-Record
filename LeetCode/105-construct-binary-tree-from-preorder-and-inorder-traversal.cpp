///////////////////////////////////////////////////////////////////////////////////////////////
// classic recursion
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode();
        root->val = preorder[0];
        int mid = -1;
        for (int i=0 ; i<preorder.size() ; i++){
            if (inorder[i] == preorder[0]){
                mid = i;
                break;
            }
        }
        vector<int> left_pre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> left_in(inorder.begin(), inorder.begin()+mid);
        TreeNode* left = buildTree(left_pre, left_in);
        
        vector<int> right_pre(preorder.begin()+mid+1, preorder.end());
        vector<int> right_in(inorder.begin()+mid+1, inorder.end());
        TreeNode* right = buildTree(right_pre, right_in);
        
        root->left = left;
        root->right = right;
        return root;
    }
};