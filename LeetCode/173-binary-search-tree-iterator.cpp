///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class BSTIterator {
public:
    vector<int> v;
    int idx;
    BSTIterator(TreeNode* root) {
        inorder(root);
        idx = -1;
    }
    
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        idx++;
        return v[idx];
    }
    
    bool hasNext() {
        return idx==(v.size()-1)?false:true;
    }
};