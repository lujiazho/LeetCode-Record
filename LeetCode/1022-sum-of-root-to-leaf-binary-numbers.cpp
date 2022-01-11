///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n), number of nodes
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> v;
    int res = 0;
    int sumRootToLeaf(TreeNode* root) {
        v.push_back(root->val);
        dfs(root);
        return res;
    }
    void dfs(TreeNode* node){
        if (node->left == NULL && node->right == NULL){
            int val = 0;
            for (int i=0 ; i<v.size() ; i++){
                val <<= 1;
                val += v[i];
            }
            res += val;
            return;
        }
        if (node->left != NULL){
            v.push_back(node->left->val);
            dfs(node->left);
            v.pop_back();
        }
        if (node->right != NULL){
            v.push_back(node->right->val);
            dfs(node->right);
            v.pop_back();
        }
    }
};