///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<TreeNode*>> stack;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> record;
        dfs(root, record, p, q);
        
        if (stack.size() == 2){
            int idx = 0, range=min(stack[0].size(), stack[1].size());
            while (idx < range && stack[0][idx]->val == stack[1][idx]->val)
                idx ++;
            return stack[0][idx-1];
        }else return NULL;
    }
    void dfs(TreeNode* node, vector<TreeNode*>& cur, TreeNode* p, TreeNode* q){
        if (!node) return;
        cur.push_back(node);
        if (node->val == p->val || node->val == q->val) 
            stack.push_back(vector<TreeNode*>(cur));
        if (node->left) dfs(node->left, cur, p, q);
        if (node->right) dfs(node->right, cur, p, q);
        cur.pop_back();
    }
};·